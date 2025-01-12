## C++ モジュール01-02課題: Warlockクラスへの呪文とターゲットの追加

**課題名:** cpp01_02
**提出ファイル:** Warlock.cpp Warlock.hpp, ASpell.hpp ASpell.cpp, ATarget.hpp ATarget.cpp, Fwoosh.hpp Fwoosh.cpp, Dummy.hpp Dummy.cpp

Warlockクラスでは、switch文の使用は**禁止**されており、使用した場合-42点の減点となります。

### ASpell抽象クラス

以下のprotected属性を持つASpell抽象クラスをCoplienの形式で作成してください。

* name (string): 呪文の名前
* effects (string): 呪文の効果

両属性には、stringを返すゲッター（getName、getEffects）を用意します。

また、ASpellへのポインタを返す純粋仮想関数clone()も追加します。

これらの関数はすべてconstオブジェクトに対して呼び出すことができます。

ASpellのコンストラクタは、名前と効果をこの順序で引数にとります。

### ATarget抽象クラス

Coplienの形式でATarget抽象クラスを作成します。このクラスはstring型のtype属性と、const stringへの参照を返す対応するゲッターgetType()を持ちます。

ASpellと同様に、純粋仮想関数clone()を持ちます。

これらの関数はすべてconstオブジェクトに対して呼び出すことができます。

ATargetのコンストラクタは、タイプを引数にとります。

ATargetに、const ASpellへの参照を引数にとるgetHitBySpell()関数を追加します。

この関数は以下のメッセージを表示します。

```
<TYPE> has been <EFFECTS>!
```

`<TYPE>`はATargetのタイプ、`<EFFECTS>`はASpellのgetEffects()関数の戻り値です。

### ASpellのlaunch関数

ASpellクラスに、const ATargetへの参照を引数にとるlaunch()関数を追加します。

この関数は、渡されたオブジェクトのgetHitBySpell()を呼び出し、現在のインスタンスを引数として渡します。

### FwooshクラスとDummyクラス

ASpellの実装クラスとしてFwooshを作成します。デフォルトコンストラクタは、名前を"Fwoosh"、効果を"fwooshed"に設定します。もちろん、clone()メソッドも実装します。Fwooshの場合、新しいFwooshオブジェクトへのポインタを返します。

同様に、具体的なATargetとしてDummyを作成します。そのタイプは"Target Practice Dummy"です。clone()メソッドも実装する必要があります。

### Warlockクラスへの追加

Warlockクラスに以下のメンバー関数を追加します。

* learnSpell(ASpell*): Warlockに呪文を覚えさせる
* forgetSpell(const string&): 呪文の名前を表す文字列を引数に取り、Warlockに呪文を忘れさせます。知らない呪文の場合は何もしません。
* launchSpell(const string&, ATarget&): 呪文の名前とATargetへの参照を引数に取り、選択したターゲットに呪文を発動します。知らない呪文の場合は何もしません。

Warlockが知っている呪文を格納するために、新しい属性が必要です。いくつかの型が適していますが、最適な型を選択するのはあなた次第です。

### テスト用main関数と期待される出力

```c++
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
```

```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$
```


This assignment builds upon the previous one, adding spells and targets to the `Warlock` class.  You'll need to create abstract classes for spells (`ASpell`) and targets (`ATarget`), along with concrete implementations (`Fwoosh` and `Dummy`).  The `Warlock` class needs to be extended to learn, forget, and launch spells.  The provided code example shows the expected interactions and output.  Note the explicit prohibition of the `switch` statement within the `Warlock` class.
