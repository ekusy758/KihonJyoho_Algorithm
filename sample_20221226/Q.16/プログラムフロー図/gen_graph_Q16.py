from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（codePoint を受け取る）')
dot.node('init', '配列 utf8Bytes を\n{224, 128, 128}で初期化')
dot.node('set_cp', 'cp に codePoint を代入')
dot.node('loop', 'i を 2 から 0 まで繰り返す', shape='diamond', fillcolor='lightblue')
dot.node('extract', 'cp の下位6ビットを抽出（cp % 64）')
dot.node('add_byte', 'utf8Bytes[i] に抽出した値を加算')
dot.node('shift', 'cp を6ビット右にずらす（cp ÷ 64）')
dot.node('next', '次の i へ', shape='ellipse', fillcolor='lightgrey')
dot.node('ret', 'utf8Bytes を返す')
dot.node('end', '終了')

dot.edge('start', 'init')
dot.edge('init', 'set_cp')
dot.edge('set_cp', 'loop')
dot.edge('loop', 'extract', label='Yes')
dot.edge('extract', 'add_byte')
dot.edge('add_byte', 'shift')
dot.edge('shift', 'next')
dot.edge('next', 'loop')
dot.edge('loop', 'ret', label='No')
dot.edge('ret', 'end')

dot.render('graph_Q16', view=True, cleanup=True)
