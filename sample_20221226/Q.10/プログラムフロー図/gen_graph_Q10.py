from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（pos を受け取る）')
dot.node('check1', 'pos == 1?', shape='diamond', fillcolor='lightblue')
dot.node('setHead', '先頭要素の次を先頭に設定')
dot.node('setPrev', 'prev を先頭要素に設定')
dot.node('check2', 'pos != 2?', shape='diamond', fillcolor='lightblue')
dot.node('loop', 'i を pos - 1 以上になるまで進める')
dot.node('del', '次の要素 を次の次の要素に更新')
dot.node('end', '終了')

dot.edge('start', 'check1')
dot.edge('check1', 'setHead', label='Yes')
dot.edge('setHead', 'end')
dot.edge('check1', 'setPrev', label='No')
dot.edge('setPrev', 'check2')
dot.edge('check2', 'loop', label='Yes')
dot.edge('loop', 'del')
dot.edge('check2', 'del', label='No')
dot.edge('del', 'end')

dot.render('graph_Q10', view=True, cleanup=True)
