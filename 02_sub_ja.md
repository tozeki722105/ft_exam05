## C++ モジュール02課題: Warlock、呪文、ターゲットの拡張

**課題名:** cpp_module_02
**提出ファイル:** Warlock.cpp Warlock.hpp, ASpell.hpp ASpell.cpp, ATarget.hpp ATarget.cpp, Fwoosh.hpp Fwoosh.cpp, Dummy.hpp Dummy.cpp, Fireball.hpp Fireball.cpp, Polymorph.hpp Polymorph.cpp, BrickWall.hpp BrickWall.cpp, SpellBook.hpp SpellBook.cpp, TargetGenerator.hpp TargetGenerator.cpp

Warlock、SpellBook、TargetGeneratorクラスでは、switch文の使用は**禁止**されており、使用した場合-42点の減点となります。

### 新しい呪文とターゲット

Fwooshと同様のモデルで、以下の2つの呪文を作成します。

* Fireball (名前: "Fireball", 効果: "burnt to a crisp")
* Polymorph (名前: "Polymorph", 効果: "turned into a critter")

さらに、攻撃対象をダミーだけではないように、新しいターゲットBrickWall (タイプ: "Inconspicuous Red-brick Wall") を作成します。

### SpellBookクラス

コピーやコピーコンストラクタによるインスタンス化ができない、標準的な形式のSpellBookクラスを作成します。以下の関数を持たせます。

* learnSpell(ASpell*): 呪文をSpellBookに**コピー**して追加する
* forgetSpell(const string&): 指定された名前の呪文をSpellBookから削除する。存在しない場合は何もしない
* createSpell(const string&): 指定された名前の呪文を**新しく作成**し、そのポインタを返す

### Warlockクラスの変更

Warlockクラスを変更し、SpellBookをメンバー変数として持ち、Warlockの作成と同時に作成され、破棄と同時に破棄されるようにします。また、WarlockのlearnSpell()関数とforgetSpell()関数は、SpellBookの対応する関数を呼び出すように変更します。

launchSpell()関数は、SpellBookを使用して発動しようとしている呪文を作成する必要があります。

### TargetGeneratorクラス

コピー不可で、標準的な形式のTargetGeneratorクラスを作成します。以下の関数を持たせます。

* learnTargetType(ATarget*): ターゲットのタイプをジェネレータに学習させる
* forgetTargetType(const string&): 指定されたタイプのターゲットをジェネレータから削除する。存在しない場合は何もしない
* createTarget(const string&): 指定されたタイプのターゲットを**新しく作成**し、そのポインタを返す

### テスト用main関数

以下はテスト用のmain関数です。網羅的なテストではないため、独自のテストも必ず実施してください。

```c++
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
```

```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
```

This assignment expands on the previous ones by introducing a `SpellBook` and `TargetGenerator` to manage spells and targets, respectively.  You will create new spells (Fireball, Polymorph) and a new target (BrickWall).  The `Warlock` now utilizes a `SpellBook` to store and retrieve spells, and a `TargetGenerator` is used to create targets.  The provided code example demonstrates the interaction between these classes. The `switch` statement remains prohibited within the `Warlock`, `SpellBook`, and `TargetGenerator` classes.  It emphasizes proper memory management and the importance of thorough testing beyond the provided example.
