from graphviz import Digraph

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（文字c1, c2 を受け取る）')
dot.node('makeStr', 'c1, c2 を1文字の文字列に変換\n→ s1, s2')
dot.node('check', 's1 + s2 は出現する？', shape='diamond', fillcolor='lightblue')
dot.node('calc', '出現率 = freq(s1 + s2) ÷ (freq(s1) - freqE(s1))')
dot.node('retProb', '出現率を返す')
dot.node('retZero', '0 を返す（出現しない）')
dot.node('end', '終了')

dot.edge('start', 'makeStr')
dot.edge('makeStr', 'check')
dot.edge('check', 'calc', label='Yes')
dot.edge('calc', 'retProb')
dot.edge('check', 'retZero', label='No')
dot.edge('retProb', 'end')
dot.edge('retZero', 'end')

dot.render('graph_Q5', view=True, cleanup=True)
