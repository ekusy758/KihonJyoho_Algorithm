from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（配列 data を受け取る）')
dot.node('init', '変数 n に data のサイズを代入\nbins に data をコピー')
dot.node('loop_cond', 'i < n か？', shape='diamond', fillcolor='lightblue')
dot.node('assign', 'bins[data[i] - 1] に data[i] を代入')
dot.node('inc', 'i を1増やす', shape='ellipse', fillcolor='lightgrey')
dot.node('ret', 'bins を返す')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'loop_cond')
dot.edge('loop_cond', 'assign', label='Yes')
dot.edge('assign', 'inc')
dot.edge('inc', 'loop_cond')
dot.edge('loop_cond', 'ret', label='No')
dot.edge('ret', 'end')

dot.render('graph_Q11', view=True, cleanup=True)
