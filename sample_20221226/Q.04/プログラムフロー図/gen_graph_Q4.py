from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

# ノード定義
dot.node('start', '開始（2つの整数を受け取る）')
dot.node('init', 'x ← num1\ny ← num2')
dot.node('loopCond', 'x と y が等しくない？', shape='diamond', fillcolor='lightblue')
dot.node('xGreater', 'x > y ?', shape='diamond', fillcolor='lightblue')
dot.node('subX', 'x ← x - y')
dot.node('subY', 'y ← y - x')
dot.node('loopBack', '次の比較へ', shape='ellipse', fillcolor='lightgrey')
dot.node('ret', 'x を返す（最大公約数）')
dot.node('end', '終了')

# フロー定義
dot.edge('start', 'init')
dot.edge('init', 'loopCond')
dot.edge('loopCond', 'xGreater', label='Yes')
dot.edge('xGreater', 'subX', label='Yes')
dot.edge('subX', 'loopBack')
dot.edge('xGreater', 'subY', label='No')
dot.edge('subY', 'loopBack')
dot.edge('loopBack', 'loopCond')
dot.edge('loopCond', 'ret', label='No')
dot.edge('ret', 'end')

# 出力
dot.render('graph_Q4', view=True, cleanup=True)
