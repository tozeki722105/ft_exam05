## C++ モジュール00課題: Warlockクラスの作成

**課題名:** cpp_module_00
**提出ファイル:** Warlock.cpp Warlock.hpp

WarlockクラスをCoplienの形式に従って作成してください。

### プライベート属性

以下のプライベート属性を持たせます。

* name (string): 名前
* title (string): 肩書き

これらはプライベートなので、以下のゲッターを用意します。

* getName(): const stringへの参照を返す
* getTitle(): const stringへの参照を返す

これらの関数はどちらもconstなWarlockオブジェクトに対して呼び出し可能でなければなりません。

以下のセッターを作成します。

* setTitle(const string&): voidを返し、const stringへの参照を引数にとる

Warlockクラスは、Coplienの形式で必要なものの他に、名前と肩書きを引数にとるコンストラクタを持つ必要があります。Warlockクラスはコピー、コピーコンストラクタによるインスタンス化、名前と肩書きなしのインスタンス化ができません。

例:

```c++
Warlock bob;                            //コンパイルエラー
Warlock bob("Bob", "the magnificent");  //コンパイルOK
Warlock jim("Jim", "the nauseating");   //コンパイルOK
bob = jim;                              //コンパイルエラー
Warlock jack(jim);                      //コンパイルエラー
```

Warlockオブジェクトが作成された際に、以下のメッセージを出力します。

```
<NAME>: This looks like another boring day.
```

`<NAME>`のようなプレースホルダーは、適切な値に置き換えてください（`<` と `>` は不要）。

Warlockオブジェクトが破棄される際に、以下のメッセージを出力します。

```
<NAME>: My job here is done!
```

Warlockは自己紹介する機能も必要です。

以下の関数を記述してください。

* void introduce() const;

この関数は以下のメッセージを表示します。

```
<NAME>: I am <NAME>, <TITLE>!
```

テスト用のmain関数と実行結果の例:

```c++
int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
```

```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$
~$
```


This assignment asks you to create a `Warlock` class in C++ following Coplien's form.  The class should manage a name and title, prevent copying, and provide specific output upon construction and destruction.  Getters for the name and title (usable on const objects) and a setter for the title are required, along with an `introduce()` method for the Warlock to announce themselves.  The provided code examples illustrate expected behavior and output.
