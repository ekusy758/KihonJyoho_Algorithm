# KihonJyoho_Algorithm
～基本情報技術者試験 科目B アルゴリズム学習支援プロジェクト～

このプロジェクトは科目Bが解けなくて困っている人を助けるために立ち上げました。<br>
C/C++でプログラムを組みながら、一緒にアルゴリズムを勉強していきましょう。<br>

なお、このリポジトリは **DeepWiki**によるドキュメント化を導入しています。

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/ekusy758/KihonJyoho_Algorithm)

## フォルダ構成
- sample_20220425 : IPAが2022年04月25日に公開したサンプル問題の実装コード（問1～問5がアルゴリズム）
                    [問題冊子](https://www.ipa.go.jp/shiken/syllabus/ps6vr7000000oett-att/fe_kamoku_b_sample.pdf)
- sample_20221226 : IPAが2022年12月26日に公開したサンプル問題の実装コード（問1～問16がアルゴリズム）
                    [問題冊子](https://www.ipa.go.jp/shiken/syllabus/henkou/2022/ssf7ph000000h5tb-att/fe_kamoku_b_set_sample_qs.pdf)

## 開発基準
- 疑似言語では手続き型とオブジェクト指向が半端に(?)混在しており、構造的に最も近いC言語/C++を開発言語として採用します。
- プログラム仕様は問題に準拠します。記述のわかりやすさを優先し、複雑な構文は避けるようにします。<br>
（例）C++ではconst参照渡しではなく、あえて値渡しとする場合があります。<br>
- C言語/C++ソースファイルの文字コードは、Windowsコマンドプロンプトでの実行を想定しShift_JISとします。<br>
- アルゴリズム構造を可視化するため、プログラムフロー図をpythonの[graphviz](https://graphviz.org/)ライブラリで作成します。

## 開発環境
- OS : Windows 10 64bit
- コンパイラ :
  - g++ (C++) 8.1.0 (x86_64-posix-seh, MinGW-w64 project)
  - gcc 8.1.0 (x86_64-posix-seh, MinGW-w64 project)

## ライセンス
このプロジェクトは [MIT License](LICENSE) に基づいて公開されています。
