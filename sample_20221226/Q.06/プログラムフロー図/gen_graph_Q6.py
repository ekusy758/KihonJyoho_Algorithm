from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始')
dot.node('init', 'rbyte に byte を代入\nr を 00000000 に初期化')
dot.node('loop_cond', 'i < 8 ?', shape='diamond', fillcolor='lightblue')
dot.node('shift_and_merge', 'r を左に1ビットシフト\nrbyte の最下位ビットを r に加える')
dot.node('shift_rbyte', 'rbyte を右に1ビットシフト')
dot.node('inc_i', 'i を1増やす', shape='ellipse', fillcolor='lightgrey')
dot.node('ret', 'r を返す')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'loop_cond')
dot.edge('loop_cond', 'shift_and_merge', label='Yes')
dot.edge('shift_and_merge', 'shift_rbyte')
dot.edge('shift_rbyte', 'inc_i')
dot.edge('inc_i', 'loop_cond')
dot.edge('loop_cond', 'ret', label='No')
dot.edge('ret', 'end')

dot.render('graph_Q6', view=True, cleanup=True)
