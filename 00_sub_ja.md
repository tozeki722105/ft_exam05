課題名：cpp_module_00
提出ファイル：Warlock.cpp Warlock.hpp
--------------------------------------------------------------------------------

Warlockクラスを作成します。Coplienの形式に従う必要があります。

以下のprivate属性を持ちます。
* name (string)
* title (string)

これらはprivateなので、以下のゲッターを作成します。
* getName：const stringへの参照を返す
* getTitle：const stringへの参照を返す

これらの関数はどちらもconstなWarlockオブジェクトで呼び出せる必要があります。

以下のセッターを作成します。
* setTitle：voidを返し、const stringへの参照を引数にとる

Warlockは、Coplienの形式で必要なものに加えて、名前と肩書きをこの順序で引数にとるコンストラクタも持ちます。Warlockはコピー、コピーコンストラクタによるインスタンス化、または名前と肩書きなしのインスタンス化はできません。

例：

Warlock bob;                            //コンパイルエラー
Warlock bob("Bob", "the magnificent");  //コンパイルOK
Warlock jim("Jim", "the nauseating");   //コンパイルOK
bob = jim;                              //コンパイルエラー
Warlock jack(jim);                      //コンパイルエラー

作成時に、Warlockは以下のように言います。

<NAME>: 今日もお暇そうですね。

もちろん、<NAME>、<TITLE>などのプレースホルダーを使用する場合は、適切な値に置き換えてください。<と>は不要です。

死ぬとき、彼は以下のように言います。

<NAME>: 私の仕事は終わりました！

Warlockは、自分の能力を誇示しながら自己紹介できる必要があります。

そのため、以下の関数を作成します。
* void introduce() const;

以下のように表示する必要があります。

<NAME>: 私は<NAME>、<TITLE>です！

テスト用のmain関数とその出力例を以下に示します。

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

~$ ./a.out | cat -e
Richard: 今日もお暇そうですね。$
Richard: 私はRichard、Mistress of Magmaです！$
Richard - Mistress of Magma$
Jack: 今日もお暇そうですね。$
Jack: 私はJack、the Longです！$
Jack: 私はJack、the Mightyです！$
Jack: 私の仕事は終わりました！$
Richard: 私の仕事は終わりました！$
~$
