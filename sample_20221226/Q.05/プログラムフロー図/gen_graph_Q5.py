from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始 (x, yを受け取る)')
dot.node('calcPowX', 'xの2乗を計算')
dot.node('calcPowY', 'yの2乗を計算')
dot.node('sum', 'x² + y² を計算')
dot.node('sqrt', '平方根を計算 (pow(…, 0.5))')
dot.node('return', '結果を返す')
dot.node('end', '終了')

dot.edge('start', 'calcPowX')
dot.edge('calcPowX', 'calcPowY')
dot.edge('calcPowY', 'sum')
dot.edge('sum', 'sqrt')
dot.edge('sqrt', 'return')
dot.edge('return', 'end')

dot.render('graph_Q5', view=True, cleanup=True)
