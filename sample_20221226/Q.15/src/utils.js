/* 2分木の進行方向を記録 */
let direction = null;

/* 盤面パターンと表示するBoardコンポーネント、進行方向を定義するオブジェクトおよびオブジェクト配列のデータ構造を定義 */
const BOARD_TRANSITIONS = {
  r: {
    pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', null, null],
    boardIndex: 0,
    setDirection: 'right',
  },
  c: {
    pattern: ['X', 'O', 'X', 'X', 'O', 'O', null, 'O', null],
    boardIndex: 1,
  },
  l: {
    pattern: ['X', 'O', 'X', 'X', 'O', 'O', null, null, 'O'],
    boardIndex: 2,
    setDirection: 'left',
  },
  rr: [
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', null], boardIndex: 3 },
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O'], boardIndex: 7 },
  ],
  rl: [
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', null, 'X'], boardIndex: 4 },
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'X'], boardIndex: 8 },
  ],
  lr: {
    pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'X', null, 'O'],
    boardIndex: 5,
  },
  ll: [
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', null, 'X', 'O'], boardIndex: 6 },
    { pattern: ['X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O'], boardIndex: 10 },
  ],
};

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

/* 盤面の状態に基づいてBoardコンポーネントを表示する */
export function displayNextBoard(nextSquares, visibleBoards, setVisibleBoards) {
  for (const key of ['r', 'c', 'l']) {
    const transition = BOARD_TRANSITIONS[key];
    if (arraysEqual(nextSquares, transition.pattern)) {
      setVisibleBoards(visibleBoards.map((v, i) => i === transition.boardIndex ? true : v));
      if (transition.setDirection) {
        direction = transition.setDirection;
      }
      return;
    }
  }

  if (direction === 'right') {
    const rrMatch = BOARD_TRANSITIONS.rr.find(item => arraysEqual(nextSquares, item.pattern));
    if (rrMatch) {
      setVisibleBoards(visibleBoards.map((v, i) => i === rrMatch.boardIndex ? true : v));
      return;
    }

    const rlMatch = BOARD_TRANSITIONS.rl.find(item => arraysEqual(nextSquares, item.pattern));
    if (rlMatch) {
      setVisibleBoards(visibleBoards.map((v, i) => i === rlMatch.boardIndex ? true : v));
      return;
    }
  } else if (direction === 'left') {
    const llMatch = BOARD_TRANSITIONS.ll.find(item => arraysEqual(nextSquares, item.pattern));
    if (llMatch) {
      setVisibleBoards(visibleBoards.map((v, i) => i === llMatch.boardIndex ? true : v));
      return;
    }
  }

  const lrTransition = BOARD_TRANSITIONS.lr;
  if (arraysEqual(nextSquares, lrTransition.pattern)) {
    setVisibleBoards(visibleBoards.map((v, i) => i === lrTransition.boardIndex ? true : v));
    return;
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

