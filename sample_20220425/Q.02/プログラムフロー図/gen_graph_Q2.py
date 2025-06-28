from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始')
dot.node('init', '配列を初期化 {1,2,3,4,5}')
dot.node('cond', '左端の位置を0とする;\n要素数÷2の商より小さい?', shape='diamond', fillcolor='lightblue')
dot.node('calc', '右端の位置を取得(要素数-左端の位置)')
dot.node('swap', '配列の右端と左端の要素を交換')
dot.node('inc', '左端の位置を1増やす', shape='ellipse', fillcolor='lightgrey')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'cond')
dot.edge('cond', 'calc', label='Yes')
dot.edge('calc', 'swap')
dot.edge('swap', 'inc')
dot.edge('inc', 'cond') 
dot.edge('cond', 'end', label='No')

dot.render('graph_Q2', cleanup=True)
