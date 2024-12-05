課題名：cpp01_02
提出ファイル：Warlock.cpp Warlock.hpp
                   ASpell.hpp ASpell.cpp
				   ATarget.hpp ATarget.cpp
				   Fwoosh.hpp Fwoosh.cpp
				   Dummy.hpp Dummy.cpp
--------------------------------------------------------------------------------

Warlockクラスでは、switch文は**禁止**されており、使用すると-42点となります。

以下のprotected属性を持つASpellという抽象クラスをCoplienの形式で作成します。

* name (string)
* effects (string)

どちらも文字列を返すゲッター（getNameとgetEffects）を持ちます。

また、ASpellへのポインタを返す純粋仮想関数cloneも追加します。

これらの関数はすべてconstオブジェクトで呼び出すことができます。

ASpellには、名前と効果をこの順序で引数にとるコンストラクタがあります。

次に、Coplienの形式でATargetという抽象クラスを作成します。これはstring型のtype属性とその関連ゲッターであるgetTypeを持ち、const stringへの参照を返します。

ASpellと同様に、純粋仮想関数clone()を持ちます。

これらの関数はすべてconstオブジェクトで呼び出すことができます。

typeを引数にとるコンストラクタがあります。

次に、ATargetにconst ASpellへの参照を引数にとるgetHitBySpell関数を追加します。

これは以下のように表示します。

<TYPE> は <EFFECTS> されました！

<TYPE> はATargetのtype、<EFFECTS> はASpellのgetEffects関数の戻り値です。

最後に、ASpellクラスにconst ATargetへの参照を引数にとるlaunch関数を追加します。

これは、渡されたオブジェクトのgetHitBySpellを呼び出し、現在のインスタンスを引数として渡します。

これらがすべて完了したら、FwooshというASpellの実装を作成します。デフォルトコンストラクタは名前を"Fwoosh"に、効果を"fwooshed"に設定します。もちろん、clone()メソッドも実装します。Fwooshの場合、新しいFwooshオブジェクトへのポインタを返します。

同様に、"Target Practice Dummy"というタイプのDummyという具象ATargetを作成します。clone()メソッドも実装する必要があります。

Warlockに以下のメンバー関数を追加します。

* learnSpell：ASpellへのポインタを引数に取り、Warlockに呪文を学習させる
* forgetSpell：呪文の名前に対応する文字列を引数に取り、Warlockにそれを忘れさせる。既知の呪文でない場合は何もしない。
* launchSpell：文字列（呪文の名前）とATargetへの参照を引数に取り、選択したターゲットに呪文を発動する。既知の呪文でない場合は何もしない。

Warlockが知っている呪文を格納するための新しい属性が必要です。いくつかの型が適していますが、最適な型を選択するのはあなた次第です。

以下はテスト用のmain関数とその期待される出力です。

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}

~$ ./a.out | cat -e
Richard: 今日もお暇そうですね。$
Richard: 私はRichard、the Titledです！$
Target Practice Dummy は fwooshed されました！$
Richard: 私の仕事は終わりました！$
