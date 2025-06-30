from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始')
dot.node('init', '優先度付きキュー prioQueue を初期化')
dot.node('enqueue1', 'enqueue("A", 1)\nenqueue("B", 2)\nenqueue("C", 2)\nenqueue("D", 3)')
dot.node('dequeue1', 'dequeue() x 2 (戻り値未使用)')
dot.node('enqueue2', 'enqueue("D", 3)\nenqueue("B", 2)')
dot.node('dequeue2', 'dequeue() x 2 (戻り値未使用)')
dot.node('enqueue3', 'enqueue("C", 2)\nenqueue("A", 1)')
dot.node('loop_check', 'キュー内の要素数が0?', shape='diamond', fillcolor='lightblue')
dot.node('dequeue_loop', 'dequeue() の戻り値を出力', shape='ellipse', fillcolor='lightgrey')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'enqueue1')
dot.edge('enqueue1', 'dequeue1')
dot.edge('dequeue1', 'enqueue2')
dot.edge('enqueue2', 'dequeue2')
dot.edge('dequeue2', 'enqueue3')
dot.edge('enqueue3', 'loop_check')
dot.edge('loop_check', 'dequeue_loop', label='Yes')
dot.edge('dequeue_loop', 'loop_check')
dot.edge('loop_check', 'end', label='No')

dot.render('graph_Q8', view=True, cleanup=True)
