from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始')
dot.node('declare', '変数 x, y, z を\nそれぞれ 1, 2, 3 で初期化')
dot.node('assign1', 'x ← y')
dot.node('assign2', 'y ← z')
dot.node('assign3', 'z ← x')
dot.node('print', 'y, z を出力（3, 2）')
dot.node('end', '終了')

dot.edge('start', 'declare')
dot.edge('declare', 'assign1')
dot.edge('assign1', 'assign2')
dot.edge('assign2', 'assign3')
dot.edge('assign3', 'print')
dot.edge('print', 'end')

dot.render('graph_Q1', view=True, cleanup=True)
