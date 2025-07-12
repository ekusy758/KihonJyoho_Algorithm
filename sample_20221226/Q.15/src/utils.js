let direction = null;

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

export function removeUncheckedClass(nextSquares) {
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

  const uncheckedBoard = document.querySelector('.Unchecked');
  uncheckedBoard.classList.remove('Unchecked');

  const childBoard = uncheckedBoard.children;
  if (arraysEqual(nextSquares, r)) {
    childBoard[0].classList.remove('hidden');
    direction = 'right';
  } else if (arraysEqual(nextSquares, c)) {
    childBoard[1].classList.remove('hidden');
  } else if (arraysEqual(nextSquares, l)) { 
    childBoard[2].classList.remove('hidden');
    direction = 'left';
  } else if (direction === 'right' && rr.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoard[0].classList.remove('hidden');
  } else if (rl.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoard[1].classList.remove('hidden');
  } else if (lr.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoard[2].classList.remove('hidden');
  } else if (direction === 'left' && ll.some(pattern => arraysEqual(nextSquares, pattern))) {
    childBoard[3].classList.remove('hidden');
  }
}

function arraysEqual(a, b) {
  return (
    Array.isArray(a) &&
    Array.isArray(b) &&
    a.length === b.length &&
    a.every((val, i) => val === b[i])
  );
}