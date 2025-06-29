from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（引数 n を受け取る）')
dot.node('cond', 'n == 0?', shape='diamond', fillcolor='lightblue')
dot.node('ret1', '1 を返す')
dot.node('rec', 'n * factorial(n - 1) を返す')
dot.node('end', '終了')

dot.edge('start', 'cond')
dot.edge('cond', 'ret1', label='Yes')
dot.edge('cond', 'rec', label='No')
dot.edge('ret1', 'end')
dot.edge('rec', 'end')

dot.render('graph_Q7', view=True, cleanup=True)
