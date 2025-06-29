from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（整数配列を受け取る）')
dot.node('init', '新しい配列 out を作成\nout に in[0] を追加')
dot.node('loopCond', 'i < in の要素数 ?', shape='diamond', fillcolor='lightblue')
dot.node('getTail', 'out の末尾を取得（tail）')
dot.node('calc', 'tail + in[i] を out に追加')
dot.node('inc', 'i を1増やす', shape='ellipse', fillcolor='lightgrey')
dot.node('ret', 'out を返す')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'loopCond')
dot.edge('loopCond', 'getTail', label='Yes')
dot.edge('getTail', 'calc')
dot.edge('calc', 'inc')
dot.edge('inc', 'loopCond')
dot.edge('loopCond', 'ret', label='No')
dot.edge('ret', 'end')

dot.render('graph_Q3', view=True, cleanup=True)
