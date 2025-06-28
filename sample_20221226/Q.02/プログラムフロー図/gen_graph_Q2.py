from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（数値を受け取る）')
dot.node('cond1', '3と5の両方で割り切れる？', shape='diamond', fillcolor='lightblue')
dot.node('retBoth', '3と5で割り切れる')
dot.node('cond2', '3で割り切れる？', shape='diamond', fillcolor='lightblue')
dot.node('ret3', '3で割り切れる')
dot.node('cond3', '5で割り切れる？', shape='diamond', fillcolor='lightblue')
dot.node('ret5', '5で割り切れる')
dot.node('retNone', '3でも5でも割り切れない')
dot.node('return', '結果を返す')
dot.node('end', '終了')

dot.edge('start', 'cond1')
dot.edge('cond1', 'retBoth', label='Yes')
dot.edge('retBoth', 'return')

dot.edge('cond1', 'cond2', label='No')
dot.edge('cond2', 'ret3', label='Yes')
dot.edge('ret3', 'return')

dot.edge('cond2', 'cond3', label='No')
dot.edge('cond3', 'ret5', label='Yes')
dot.edge('ret5', 'return')

dot.edge('cond3', 'retNone', label='No')
dot.edge('retNone', 'return')
dot.edge('return', 'end')

dot.render('graph_Q2', view=True, cleanup=True)
