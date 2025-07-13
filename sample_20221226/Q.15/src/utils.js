/* 2分木の進行方向を記録 */
let direction = null;

/* ゲームの勝敗を判定 */
export function calculateWinner(squares) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];

  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      if (squares[a] === 'O') {
        return '勝ち 評価値 10';
      } else if (squares[a] === 'X') {
        return '負け 評価値 －10';
      }
    }
  }

  const allSquaresFilled = squares.every(square => square !== null);
  if (allSquaresFilled) {
    return '引き分け 評価値 0';
  }

  return null;
}

/* 次のボードを表示する */
export function displayNextBoard(nextSquares) {
  // 2分木の分岐パターンを事前定義
  const r = ['X', 'O', 'X', 'X', 'O', 'O', 'O', null, null];
  const c = ['X', 'O', 'X', 'X', 'O', 'O', null, 'O', null]; // Winner 'O'
  const l = ['X', 'O', 'X', 'X', 'O', 'O', null, null, 'O'];
  const rr = [
    ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', null],
    ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O'],
  ];
  const rl = [
    ['X', 'O', 'X', 'X', 'O', 'O', 'O', null, 'X'],
    ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'X'], // Winner 'O'
  ];
  const lr = [
    ['X', 'O', 'X', 'X', 'O', 'O', 'X', null, 'O'], // Winner 'X'
  ];
  const ll = [
    ['X', 'O', 'X', 'X', 'O', 'O', null, 'X', 'O'],
    ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O'],
  ];

  // 次の未チェック領域を解除
  const uncheckedArea = document.querySelector('.Unchecked');
  uncheckedArea.classList.remove('Unchecked');

  // プレイヤーの選択に応じたBoardを表示 (hiddenクラスを削除)
  const childBoards = uncheckedArea.children;

  if (arraysEqual(nextSquares, r)) {
    childBoards[0].classList.remove('hidden');
    direction = 'right';
  } else if (arraysEqual(nextSquares, c)) {
    childBoards[1].classList.remove('hidden');
  } else if (arraysEqual(nextSquares, l)) { 
    childBoards[2].classList.remove('hidden');
    direction = 'left';
  } else if (direction === 'right' && rr.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoards[0].classList.remove('hidden');
  } else if (rl.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoards[1].classList.remove('hidden');
  } else if (lr.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoards[2].classList.remove('hidden');
  } else if (direction === 'left' && ll.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoards[3].classList.remove('hidden');
  }
}

/* 配列の各値と要素数が一致しているか検査する */
function arraysEqual(a, b) {
  return (
    Array.isArray(a) &&
    Array.isArray(b) &&
    a.length === b.length &&
    a.every((val, i) => val === b[i])
  );
}