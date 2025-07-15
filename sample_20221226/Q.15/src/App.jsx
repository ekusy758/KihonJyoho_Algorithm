import { useState } from 'react';
import { calculateWinner, displayNextBoard } from './utils.js';

function Square({value, onSquareClick}) {
  return (
    <button className="square" onClick={onSquareClick}>
      {value}
    </button>
  );
}

function Board({ xIsNext, squares, onClick, isVisible }) {
  const winner = calculateWinner(squares);
  let status;
  if (winner) {
    status = winner;
  } else {
    status = (xIsNext ? '自分' : '相手') + 'の手番';
  }

  let className;
  if (isVisible) {
    className = 'square-box';
  } else {
    className = 'square-box hidden';
  }

  return (
    <div className={className}>
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
  const [uncheckedDivs, setUncheckedDivs] = useState(['center-board', 'Unchecked', 'Unchecked', 'Unchecked']);
  const [uncheckedIndex, setUncheckedIndex] = useState(1);
  const [visibleBoards, setVisibleBoards] = useState(Array(11).fill(false));
  
  function handleClick(i) {
    if (calculateWinner(squares) || squares[i]) {
      return;
    }
    const nextSquares = squares.slice();
    nextSquares[i] = xIsNext ? 'O' : 'X';
    setSquares(nextSquares);
    setXIsNext(!xIsNext);

    displayNextBoard(nextSquares, visibleBoards, setVisibleBoards);

    const nextUncheckedDivs = uncheckedDivs.slice();
    nextUncheckedDivs[uncheckedIndex] = 'center-board';
    setUncheckedIndex(uncheckedIndex + 1);
    setUncheckedDivs(nextUncheckedDivs);
  }

  return (
    <>
      <div className="wrapper">
        <p>根の状態</p>
        <div className={`${uncheckedDivs[0]} root-node`}>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={true} />
        </div>
        <hr/>
        <div className={uncheckedDivs[1]}>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[0]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[1]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[2]} />
        </div>
        <hr/>
        <div className={uncheckedDivs[2]}>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[3]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[4]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[5]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[6]} />
        </div>
        <hr/>
        <div className={uncheckedDivs[3]}>
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[7]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[8]} />
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[9]} />{/* ゲーム上到達しなBoardd */}
          <Board xIsNext={xIsNext} squares={squares} onClick={(i) => () => handleClick(i)} isVisible={visibleBoards[10]} />
        </div>
      </div>
      <div className="footer">
        <span>図．三目並べの状態遷移</span>
        <button onClick={() => window.location.reload()}>リセット</button>
      </div>

    </>
  )
}