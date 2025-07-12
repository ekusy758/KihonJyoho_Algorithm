import { useState } from 'react';
import { calculateWinner, removeUncheckedClass } from './utils.js';

function Square({value, onSquareClick}) {
  return (
    <button className="square" onClick={onSquareClick}>
      {value}
    </button>
  );
}

function Board({ xIsNext, squares, onClick }) {
  const winner = calculateWinner(squares);
  let status;
  if (winner) {
    status = winner;
  } else {
    status = (xIsNext ? '自分' : '相手') + 'の手番';
  }

  return (
    <div className="square-box hidden">
      <div className="board-row">
        <Square value={squares[0]} onSquareClick={onClick(0)} />
        <Square value={squares[1]} onSquareClick={onClick(1)} />
        <Square value={squares[2]} onSquareClick={onClick(2)} />
      </div>
      <div className="board-row">
        <Square value={squares[3]} onSquareClick={onClick(3)} />
        <Square value={squares[4]} onSquareClick={onClick(4)} />
        <Square value={squares[5]} onSquareClick={onClick(5)} />
      </div>
      <div className="board-row">
        <Square value={squares[6]} onSquareClick={onClick(6)} />
        <Square value={squares[7]} onSquareClick={onClick(7)} />
        <Square value={squares[8]} onSquareClick={onClick(8)} />
      </div>

      <div className="status">{status}</div>
    </div>
  );
}

export default function Game() {
  const [squares, setSquares] = useState(['X', 'O', 'X', 'X', 'O', 'O', null, null, null]);
  const [xIsNext, setXIsNext] = useState(true);
  
  function handleClick(i) {
    if (calculateWinner(squares) || squares[i]) {
      return;
    }
    const nextSquares = squares.slice();
    nextSquares[i] = xIsNext ? 'O' : 'X';
    setSquares(nextSquares);
    setXIsNext(!xIsNext);

    removeUncheckedClass(nextSquares);
  }

  return (
    <>
      <div class="wrapper">
        <p>根の状態</p>
        <div className='center-board root'>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
        </div>
        <hr/>
        <div className='center-board Unchecked'>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
        </div>
        <hr/>
        <div className='center-board Unchecked'>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
        </div>
        <hr/>
        <div className='center-board Unchecked'>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} />
        </div>
      </div>
      <div class="footer">
        <span>図．三目並べの状態遷移</span>
        <button onClick={() => window.location.reload()}>リセット</button>
      </div>

    </>
  )
}