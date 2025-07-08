from graphviz import Digraph
import math

dot = Digraph(format='png')
dot.attr(rankdir='TB')
dot.attr('node', shape='box', style='filled', fontname='MS Gothic', fillcolor='lightyellow')

dot.node('start', '開始（昇順ソート済みデータを受け取る）')
dot.node('initP', 'p = {0, 0.25, 0.5, 0.75, 1} を設定')
dot.node('initRankData', 'rankData を空で初期化')
dot.node('loopCond', 'pの各値に対して繰り返す', shape='diamond', fillcolor='lightblue')
dot.node('callFindRank', 'findRankを呼び出し\n対応する値をrankDataに追加')
dot.node('retRankData', 'rankData を返す')
dot.node('end', '終了')

# findRankの中身
dot.node('findStart', 'findRank処理開始', shape='ellipse', fillcolor='lightgrey')
dot.node('calcIndex', 'i = ceil(p × (データ数 − 1))')
dot.node('returnValue', 'sortedData[i] を返す')

# summarizeの流れ
dot.edge('start', 'initP')
dot.edge('initP', 'initRankData')
dot.edge('initRankData', 'loopCond')
dot.edge('loopCond', 'callFindRank', label='Yes')
dot.edge('callFindRank', 'loopCond')
dot.edge('loopCond', 'retRankData', label='No')
dot.edge('retRankData', 'end')

# findRank の中の流れ
dot.edge('callFindRank', 'findStart', style='dashed')
dot.edge('findStart', 'calcIndex')
dot.edge('calcIndex', 'returnValue')
dot.edge('returnValue', 'callFindRank', style='dashed')

dot.render('graph_Q14', view=True, cleanup=True)
