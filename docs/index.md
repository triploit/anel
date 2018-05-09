# ANEL - A New Esoteric Programming Language

Anel ist eine kleine esoterische Programmiersprache, die sehr leicht zu lesen und verständlich sein soll.
Sie eignet sich gut, um Anfängern die Struktur des Programmierens beizubrignen, da sie der englischen Sprache sehr ähnelt.

----------------------------------------------------------

## Kapitel

0. Eine Datei kompilieren.
1. Hallo Welt!
2. Variablen erstellen
3. Werte bearbeiten
4. Output
5. If-Abfragen
6. While-Schleife
7. Gültigkeitsbereiche von Variablen
8. Input
9. Funktionen erstellen und aufrufen
10. Dateien einbinden

----------------------------------------------------------

## 0. Eine Datei kompilieren

Eine Datei kann von der Befehlszeile aus wie folgt kompiliert werden:

```bash
$ anel input.anl -o output.bin
```

Die Option `-o [Datei]` gibt die Datei an, in der das Programm nacher in Binärcode steht.
Es gibt folgende Optionen:

| Option           | Bedeutung                         |
| ---------------- | --------------------------------- |
| `-o [Datei]`     | `[Datei]` legt den Namen des Programmes fest, in das der Code kompiliert wird. |
| `-s` | Statisches kompilieren aktivieren. Damit werden alle Bibliotheken in das Programm mit eingebunden. |
| `-v` | Verbose-Mode aktivieren. Bisher noch keine Funktion. |
| `-k` | Die generierte C++-Datei behalten.                   |

## 1. Hallo Welt!

Ein einfaches Hallo Welt-Programm sieht wie folgt aus:

```
here starts main. do
    lets print "Hallo Welt!".
done.
```

## 2. Variablen erstellen

Es gibt zwei typen von Variablen: Strings und Integer. Beide sind aus verschiedenen Programmiersprachen bekannt. Der String ist ein Text, eine Zeichenkette und der Integer eine Ganzzahl.

Einen Integer mit dem Namen `a` erstellt man wiefolgt:

```
create new a as integer is 12.
```

Damit wird eine Variable vom Typen Integer mit dem Wert 12 angelegt. Einen String legt man ähnlich an. Nur `integer` ändert sich in `string`.

```
create new b as string is "Hallo Welt!".
```

## 3. Werte bearbeiten

Damit ist natürlich das bearbeiten von den Werten in Variablen gemeint. Spezialisieren wollen wir uns hier auf die Zahlenwerte, also die Integer.

### Rechnen

Mit

```
create new a as integer is 12.
lets add 1 to a.
```

erstelle ich einen Integer a mit dem Wert 12 und addiere dann 1 dazu. Am Ende steht also 13 in a.

Mit der Subtraktion funktioniert das ähnlich:

```
lets sub 1 from a.
```

Hier wurde 1 von a wieder subtrahiert. Das bedeutet, a ist nun wieder 12. Multiplizieren wir das mal mit 2:

```
lets mul 2 to a.
```

Nun wurde a mit 2 multipliziert. Am Ende steht also 24 in a. Doch das wollen wir jetzt wieder zurück auf 12 bringen, mit einer Division:

```
lets div 2 to a.
```

Nun ist a wieder 12.

### Werte setzen

Variablen kann man natürlich auch setzen:

```
create new a as integer is 12.
create new b as integer is 13.

lets set a to 1.
lets set a to b.
```

Wass passiert hier? Das ist ganz einfach. Am Anfang erstellen wir zwei Variablen, erst a mit 12 und dann b mit 13. Dann wird a auf 1 gesetzt. Dann wird a jedoch zu b gesetzt. Da b 13 ist, ist auch a dann 13.
Mit `lets set x to y.` kann man also Variablen setzen.

## 4. Output

## 5. If-Abfragen

## 6. While-Schleife

## 7. Gültigkeitsbereiche von Variablen

## 8. Input

## 9. Funtkionen erstellen und aufrufen

## 10. Dateien einbinden