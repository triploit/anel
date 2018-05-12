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

Etwas auszugeben ist ziemlich einfach. Dafür gibt es `lets print`:

```
lets print "Hallo Welt!" and newline.
lets print "Wie geht " and "es dir?".
```

Mit `and` kann man die Nachrichten miteinander verknüpfen. Man kann das and aber auch einfach weglassen und nur ein Leerzeichen setzen:

```
lets print "Hallo Welt!" newline.
lets print "Wie geht " "es dir?".
```

Man kann dann dort natürlich auch Variablen ausgeben lassen.

## 5. If-Abfragen

Mit if-Abfragen können bestimmte Bedingungen geprüft werden. Stimmen diese Bedingungen, wir der Code, den man in ihnen reingeschrieben hat, ausgeführt. Sie sehen wie folgt aus:

### Prüfen auf Gleichheit

Dies geht bei Strings und bei Integern. Dabei wird abgefragt, ob die Variablen gleich sind. Jedoch kann man Integer und String nicht vergleichen. Es geht nur mit Integer und Integer sowie String und String.

```
if a is equal to b. do
    ...
done.
```

### Prüfen auf Kleiner

Das hier funktioniert nur mit Integern. Es wird dann geprüft, ob a kleiner als b ist.

```
is a is less than b. do
    ...
done.
```

### Prüfen auf Größer

Auch hier kann man nur Integer verwenden und hier wird geprüft, ob a größer als b ist.

```
is a is greater than b. do
    ...
done.
```

### Not

Mit Not kann eine Abfrage umgekehrt werden. Das bedeutet, mit not, wird eine Abfrage auf Gleichheit, eine Abfrage auf Ungleichheit:

```
if a is not equal to b. do
    ...
done.
```

## 6. While-Schleife

Eine While-Schleife sieht genau wie eine If-Abfrage aus, bis auf zwei besondertheiten:
    1. Sie führt den Code, der in ihr steht solange aus, bis die Bedingung falsch ist.
    2. Sie heißt "While-Schleife".

Ein Beispiel für eine While-Schleife:

```
create new i as integer is 10.

while i is greater than -1. do
    lets print "I ist" and i and newline.
    lets sub 1 from i.
done.
```

Hierbei wird der Code solange ausgeführt, wie i größer als -1 ist. Da i 10 beträgt und bei jedem Schleifendurchgang um 1 verringert wird, wird 9 bis 0 (10 Zahlen insgesamt) auf der Konsole ausgegeben.

## 7. Gültigkeitsbereiche von Variablen

Kurz vorab:
```
do # Höher/Darüber gelegen

    do # Tiefer/Darunter gelegen

    done.

done.
```

Das bedeutet, sowas stimmt **NICHT**:
```
do # Darüber
done.

do # Darunter
done
```
**Das ist falsch beschriftet.** Die sind beide auf der gleichen Höhe.

Die Variablen gelten in jedem Bereich, der mit `do` Anfängt und mit `done` endet. Dabei gilt jedoch, dass man, um so tiefer man das Programm verschachtelt, man die Variablen aus höheren Bereichen verwenden kann, von tieferen jedoch nicht.
Ein Beispiel dazu:

```
here starts main. do
    create new x as integer is 10.

    if 1 is equal to 1. do
        create new y as integer is 10.

        lets print x and newline.
        lets print y and newline.
    done.
done.
```

Das funktioniert, da `x` im höher gelegenen Bereich erstellt wurde und man darauf zugreifen kann. Jedoch muss x dann natürlich vor der If-Abfrage definiert worden sein, wäre es danach, ginge es nicht.

Sowas geht nicht:

```
here starts main. do
    if 1 is equal to 1. do
        create new x as integer is 10.
    done.

    lets print x and newline.
done.
```

`x` wurde nicht im gleichen Bereich, oder im Bereich darüber definiert, sondern ist tiefer verschachtelt.

## 8. Input

```
here starts main. do
    create x as string is "".
    lets print "> ".

    lets input x.
    lets print x and newline.
done.
```

In dem Programm wird eine Variable `x` erstellt und dann entgegengenommen. Danach wird die Eingabe ausgegeben.
Mit `lets print [Variable]` kann man Variablen vom Nutzer eingeben lassen.

## 9. Funtkionen erstellen und aufrufen

Funktionen haben wir in den Beispielen schon die ganze Zeit erstellt:
```
here starts [Funktionsname]. do
    [Code ...]
done
```

Das ist eine Funktion. Aufrufen kann man sie mit dem Namen: `lets run [Name].`
Die Gültigkeit von Funktionen ist genau wie bei den Variablen, wurde Funktion X vor Funktion Y definiert, so kann man X in Y aufrufen, aber man kann nicht Y in X aufrufen, da Y später als X definiert wurde. X weiß sozusagen gar nicht, das Y überhaupt existiert.

```
here starts X. do
    lets print "Hallo von X!" and newline.
done.

here starts Y. do
    lets print "Hallo von Y!" and newline.
    lets run X.
done.
```

Wichtig ist: Es muss eine Main-Funktion existieren. Die wird, wenn das Programm gestartet wird, als erstes ausgeführt. Sie ist der Start und auch der Endpunkt. Jedoch kann man von der Main-Funktion aus, natürlich auch andere Funktionen ausführen.

## 10. Dateien einbinden

Wenne eine Datei zu lang wird, kann man Funktionen in extra Dateien auslagern.
Das sieht dann so aus:

**Datei A.anl**

```
create new a as integer is 1.
create new b as integer is 6.

# B wird eingebunden.
!B.anl

here starts main. do
    lets print "Berechne a+b! a = " and a and "; b = " and b and newline.
    lets run _add.
    lets print a and newline.
done.
```

**Datei B.anl**

```
here starts _add. do
    lets add b to a.
done.
```

Die Funktion `_add` liegt in einer anderen Datei, wurde jedoch in die Datei mit der Main-Funktion eingebunden. Der Compiler macht dann aus den zwei Dateien eine einzige, die so aussieht:

```
create new a as integer is 1.
create new b as integer is 6.

# !B.anl wurde ersetzt
here starts _add. do
    lets add b to a.
done.

here starts main. do
    lets print "Berechne a+b! a = " and a and "; b = " and b and newline.
    lets run _add.
    lets print a and newline.
done.
```

Bedeutet also, dass man mit `![DateName]` eine Datei einbinden kann.