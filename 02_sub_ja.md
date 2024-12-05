課題名：cpp_module_02
提出ファイル：Warlock.cpp Warlock.hpp
                   ASpell.hpp ASpell.cpp
				   ATarget.hpp ATarget.cpp
				   Fwoosh.hpp Fwoosh.cpp
				   Dummy.hpp Dummy.cpp
				   Fireball.hpp Fireball.cpp
				   Polymorph.hpp Polymorph.cpp
				   BrickWall.hpp BrickWall.cpp
				   SpellBook.hpp SpellBook.cpp
				   TargetGenerator.hpp TargetGenerator.cpp
--------------------------------------------------------------------------------

Warlock、SpellBook、TargetGeneratorクラスでは、switch文は**禁止**されており、使用すると-42点となります。

Fwooshと同じモデルで、以下の2つの呪文を作成します。

* Fireball (名前: "Fireball", 効果: "burnt to a crisp" (炭になるまで焼かれた))
* Polymorph (名前: "Polymorph", 効果: "turned into a critter" (小動物に変えられた))

これに加えて、攻撃対象がダミーだけにならないように、新しいターゲットを作成します。これはBrickWall（タイプ: "Inconspicuous Red-brick Wall" (目立たない赤レンガの壁)）です。

次に、コピーやコピーコンストラクタによるインスタンス化ができない、標準的な形式のSpellBookクラスを作成します。以下の関数を持たせます。

* learnSpell(ASpell*)：呪文をspellbookに**コピー**する
* forgetSpell(string const &)：spellbookから呪文を削除する。呪文が存在しない場合は何もしない
* createSpell(string const &)：呪文の名前に対応する文字列を受け取り、呪文を作成して返す

Warlockを修正し、Warlockの作成と同時に作成され、Warlockの破棄と同時に破棄されるspellbookを持たせます。また、WarlockのlearnSpell関数とforgetSpell関数がspellbookの対応する関数を呼び出すようにします。

launchSpell関数は、SpellBookを使用して発動しようとしている呪文を作成する必要があります。

標準的な形式で、前述のようにコピー不可のTargetGeneratorクラスを作成します。

以下の関数を持たせます。

* learnTargetType(ATarget*)：ジェネレーターにターゲットを学習させる
* forgetTargetType(string const &)：ジェネレーターがターゲットタイプを既知であれば忘れさせる
* createTarget(string const &)：指定されたタイプのターゲットを作成する

これで完了です。次にテスト用のmain関数を示します。あまり徹底的ではないので、必ず独自のテストも行ってください。


int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

~$ ./a.out | cat -e
Richard: 今日もお暇そうですね。$
Richard: 私はRichard、Hello, I'm Richard the Warlock!です！$
Inconspicuous Red-brick Wall は turned into a critter されました！$
Inconspicuous Red-brick Wall は burnt to a crisp されました！$
Richard: 私の仕事は終わりました！$
~$
