# C++実装に関して

## 概要
問8は優先度キューを操作するプログラムの問題です。これを標準ライブラリの **std::priority_queue**を使って実装します。

## ポイント１：優先度仕様について
本問題では「小さい値ほど優先度を高いものとする」仕様です。<br>
しかし、**Compare**のデフォルト引数は**less**となっており max-heap構造で処理されます。<br>
よって、**less**を **greater**にするなど何らかの形で min-heap構造への変換が必要です。

### クラステンプレート定義（[cpprefjp - priority_queue](https://cpprefjp.github.io/reference/queue/priority_queue.html)）
```cpp
namespace std {
  template <class T,
            class Container = std::vector<T>,
            class Compare = less<typename Container::value_type>>
  class priority_queue;
}
```

## ポイント２：dequeue仕様について
本問題では dequeueの関数定義は次のようになっています。
> 優先度付きキューからキュー内で最も優先度の高い要素を取り出して返す。
> 最も優先度の高い要素が複数あるときは，そのうちの最初に追加された要素を一つ取り出して返す。

この仕様（FIFO）により、優先度（prio）とは別に入庫順（order）を判定する比較ロジックが必要です。<br>
今回は、独自の Compare構造体で operatorを定義し、**priority_queue**初期化時に渡すことで実現しています。
