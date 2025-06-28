from graphviz import Digraph

# グラフ定義
dot = Digraph(format='png')
dot.attr(rankdir='TB') # top->bottom
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

# ノード定義
dot.node('start', '開始(年齢は0以上)')
dot.node('cond1', '3歳以下?', shape='diamond', fillcolor='lightblue')
dot.node('ret100', '入場料は100円')
dot.node('cond2', '9歳以下?', shape='diamond', fillcolor='lightblue')
dot.node('ret300', '入場料は300円')
dot.node('ret500', '入場料は500円')
dot.node('return', '入場料を返す', shape='box')

# 矢印をつなぐ
dot.edge('start', 'cond1')
dot.edge('cond1', 'ret100', label='Yes')
dot.edge('ret100', 'return')
dot.edge('cond1', 'cond2', label='No')
dot.edge('cond2', 'ret300', label='Yes')
dot.edge('ret300', 'return')
dot.edge('cond2', 'ret500', label='No')
dot.edge('ret500', 'return')

# ファイルに出力(dot中間ファイルは残さない)
dot.render('graph_Q1', cleanup=True)