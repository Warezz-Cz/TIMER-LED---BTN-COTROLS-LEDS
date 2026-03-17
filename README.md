TIMER LED_BTN controls LEDS project
===========================

Účel/Zadání/Funkce
-----------------------


1. Pomocí přerušení 16b TIMERu (TIM2, TIM3) nastavte půlperiodu blikání LED diody na přesně 400 ms.
2. Pomocí tlačítka (reaguje na hranu) přepínejte mezi třemi různými LED. Tedy: tlačítko vybírá, která LED bliká.
3. Zajistěte, že po přepnutí na další LED, předchozí LED zhasne. Rovněž zajistěte, že blikání bude plynulé -- tedy že rozsvícení a zhasnutí LED proběhne vždy ne při stisku tlačítka, ale v pevném časovém rámci, který je dán půlperiodou 400 ms.



Schéma zapojení
-----------------------

![schéma zapojení](./docs/schéma%20timer%20projekt%20readme.png)

Popis funkce
-----------------------

1. Timer skáče každých 400ms do rutiny přerušení
2. V rutině přerušení je definováno jakou LEDkou bude zrovna blikat
3. Přepínač LED reaguje na náběžnou hranu (stisk tlačítka) a pomocí milis kontroluje stav tlačítka každých 30 ms
4. proměnná led_pointer která v rutině přerušení říká, která LED má zrovna svítit je definována uint_8 => proto je nastavená aby se po hodnotě 2 vratila zpět na 0

Zhodnocení
-----------------------

Zapojení mi dalo zabrat. Museli jsme se spolužákem chvilku přemýšlet jak to udělat.
Nakonec to nebyl tak těžký projekt. timer se dal docela pochopit a když s ním ještě budu pracovat tak pochopím ten zbytek co mi chybí.
Poprvé jsme použili sonboard. Chvilku jsem s tím bojoval, protože je zapojen jinak jak deska ve škole, ale nakonec se to podařilo rozjet.
Projekt byl zajímavý a naučil mě něco co se dá využít v dalších pracích na STMku. 