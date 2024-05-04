# Smart Parking City 🚗
Prototipo di un sistema di parcheggio intelligente implementato a livello comunale, il cui obiettivo è dimostrare come l’introduzione di **dispositivi IoT** (_Internet of Things_) possa agevolare la vita delle persone.

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

## Indice
1. [Il mondo dell'IoT](#il-mondo-delliot)
2. [Panoramica del progetto](#panoramica-del-progetto)
3. [Materiali](#materiali)
4. [Circuito](#circuito)
5. [Adattamenti e conversioni dei parametri](#bugs)
6. [Licenza](#licenza)
7. [Codice](#codice)
8. [Collegamenti interdisciplinari](#collegamenti-interdisciplinari)
   
-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Il mondo dell'IoT
Prima di esplorare il progetto in sé è opportuno fare un'introduzione al concetto di Intenrt of Things.
## "Un mondo interconnesso"
Il mondo sta assistendo ad una rapida diffusione delle reti digitali, che consentono ai dispositivi di connettersi e trasmettere informazioni. Questo fenomeno, noto come ***trasformazione digitale***, consiste nell’applicazione della tecnologia digitale al fine di stimolare innovazione ed progresso.
I **sensori** sono ovunque ormai: grazie ad essi è possibile raccogliere una grande quantità di dati che possono essere archiviati, analizzati e utilizzati per una moltitudine di scopi differenti, come monitorare l'ambiente, prevedere la crescita demografica, gestire i rifiuti, migliorare la sicurezza domestica, e molti altri.

**Curiosità** 💡: La diffusione di processori economici e reti wireless ha facilitato la diffusione dei dispositivi IoT. Si prevede che entro il 2025 ci saranno 38,6 miliardi di dispositivi connessi a Internet, aumentando a 50 miliardi entro il 2030, con una media di 190 milioni di nuovi dispositivi ogni mese.

![Un mondo sempre più "interconnesso"...](https://eu-images.contentstack.com/v3/assets/blt10e444bce2d36aa8/blt212253f30ff67b32/6525326cb528befd7b152b76/IoT-internet-of-things-.jpg)

## Internet of Things
### Cosa s'intende per IoT?
> **“Internet of Things” (IoT) è una rete interconnessa di dispositivi fisici (things), che comunicano e scambiano dati per migliorare l'efficienza e l'esperienza umana in svariati settori, tramite l’utilizzo di sensori ed altre tecnologie.**

## Quali caratteristiche deve possedere un oggetto IoT?
- **Connettività:** capacità di connettersi in modo affidabile a reti, tramite tecnologie e protocolli di comunicazione efficaci.
- **Sensori e attuatori**: capacità di percepire l’ambiente attraverso sensori e di agire su di esso tramite attuatori; questa funzionalità consente al dispositivo di raccogliere dati, prendere decisioni basate su tali dati e potenzialmente influenzare l'ambiente circostante.
- **Automazione:** implementare processi autogestiti che riducono, per poi eventualmente eliminare, la necessità dell’intervento umano; l’IoT apre un nuovo mondo in cui le attività che prima richiedevano l’intervento umano possono diventare automatizzate.
- **Scalabilità:** dato che gli ambienti IoT possono variare notevolmente in termini di dimensioni e complessità, i dispositivi dovrebbero essere progettati per scalare facilmente in modo da poter essere utilizzati in piccole reti domestiche o in grandi reti industriali.
- **Sicurezza:** l'integrità e la sicurezza dei dati sono cruciali nell'ambito dell'IoT, specialmente quando si tratta di informazioni sensibili o di dispositivi critici.
- **Interoperabilità:** capacità di interagire con altri dispositivi e sistemi, essenziale per consentire una comunicazione efficace tra dispositivi di diversi produttori e piattaforme.
- **Efficienza energetica:** molti dispositivi IoT sono alimentati da batterie o sorgenti di energia limitate; l'efficienza energetica è un aspetto chiave per garantire una lunga durata della batteria e ridurre l'impatto ambientale.
- **Manutenzione remota e aggiornamenti:** essenziale per garantire che i dispositivi IoT rimangano sicuri e aggiornati nel tempo.

## Come si collegano alla rete gli oggetti IoT?
Un **sensore** deve essere collegato a una rete in modo che i dati raccolti possano essere archiviati e condivisi.
Il **controllore** si occupa di raccogliere i dati dai sensori e di garantire la connettività: può avere la capacità di prendere decisioni immediate, oppure può inviare dati a un computer più potente per l’analisi.
Tali elementi solitamente lavorano insieme a un dispositivo chiamato **attuatore**. Gli attuatori ricevono l'input elettrico e lo convertono in azione fisica.

![](https://www.electricaltechnology.org/wp-content/uploads/2021/11/Sensor-Actuator.png)

## Pro e contro
L’IoT offre numerosi **vantaggi**, consentendo la raccolta e l'analisi efficace dei dati provenienti dai sensori. Le aziende traggono beneficio da informazioni dettagliate sui loro prodotti e clienti, ottimizzando la produzione e indirizzando il marketing in modo mirato. Le città gestiscono il traffico, il riciclaggio, le esigenze sanitarie e di trasporto. Gli individui traggono benefici in termini di salute, sicurezza domestica e costi energetici ridotti.

Allo stesso tempo, è importante considerare anche gli **svantaggi**: le imprese che sviluppano dispositivi indossabili hanno accesso a informazioni personali sugli utenti; affidarsi prettamente ad acquisti online potrebbe comportare la perdita di posti di lavoro; i rivenditori sono a conoscenza di tutti gli acquisti effettuati; un'interruzione della rete può avere conseguenze catastrofiche.

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Panoramica del progetto

Lo scopo del progetto è quello di dimostrare come l’introduzione di dispositivi IoT possa agevolare la vita delle persone nel contesto reale del parcheggio (essere aggiornati in tempo reale sullo stato dei parcheggi, poter effettuare previsioni,…).

(molte immagini del risultato finale)

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Materiali

## Modellino
- Scatola di cartone 62,0 x 44,0 cm
- Cartoncino (vari elementi 3D)
- Nastro adesivo e biadesivo
- 
## Mappa
![Mappa](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/map/smart_parking_city_map.png)
*(realizzata tramite il software CorelDRAW Essentials 2021)*

La mappa illustra un percorso stradale che presenta **3 tipologie di parcheggio** distinte, ciascuna con le proprie peculiarità e scopi dimostrativi.
**N.B.:** Si precisa che la mappa è concepita esclusivamente a fini **teorici e concettuali**, pertanto alcune delle sue caratteristiche potrebbero non essere praticamente applicabili in una situazione reale su strada.

## Componenti del circuito
La tabella sottostante riporta i diversi componenti impiegati nel circuito. Per le specifiche tecniche complete consultare i rispettivi *datasheet*.
| Componente | Quantità | Descrizione |
| --- | --- | --- |
| [`Arduino UNO R4 WiFi`](https://docs.arduino.cc/hardware/uno-r4-wifi/) | 1 | **Arduino** è una piattaforma hardware e software *open-source* con cui realizzare dispositivi digitali in grado di interagire con il mondo esterno attraverso sensori e attuatori ([datasheet](https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf)). |
| [`Breadboard`](https://www.amazon.it/AZDelivery-Breadboard-830-Arduino-Raspberry/dp/B07K8PQ4B5/ref=sr_1_2_sspa?crid=1LMAFIJE2TP5X&dib=eyJ2IjoiMSJ9.xi5AD3br6MkhFSnelneIz7280DzKo1UPIgHXXQxS0vDi-8Bj8_KMO0Ft7mOEqn_c4DgwRgptPgED-dbL794yeQGaXmW2_qVZUJwOZC9koeBdMlCEWO5zqT9bsy9L2nphxe2txNQFNUz6pkFSZn8p07Ap2cJVg1HmHG6fYz52zx-99Eig9D_CrKX9PWKCvcmJHxeDd1Yq5woqp8RimPIKu8p5l6XgSiEbDgoBknKcrwAFMY1qN1KmEPWghXLIkrgJr-bDWcngQiwzBPV1lfq6UnJalqQV_hPRmeFzyHoQ3pc.CoHS3PYbmqBx3LB_7yP7nYr01mM75NqVi_AmuokDvlI&dib_tag=se&keywords=breadboard%2Bazdelivery&qid=1711213155&sprefix=breadboard%2Baz%2Caps%2C111&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | Una breadboard è una base di costruzione *solderless* utilizzata per costruire prototipi **semipermanenti** di circuiti elettronici. |
| [`Sensori ad ultrasuoni HC-SR04`](https://www.amazon.it/HC-SR04-Misuratore-Distanze-Ultrasuoni-Ultrasonic/dp/B01COSN7O6/ref=sr_1_1_sspa?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=30NWWH1A2DL14&dib=eyJ2IjoiMSJ9.YPGfdw-5BDSrtfbP8kv-6aGGle4kgcSXSrlzpcqGoPsfcnfizPwGRtIYfIKsq8itrG6JeKxwGq2DwFn2DMf3zIOc5y_8k_RRBCZPZdmaIo9Gq8HodidfIYzK55jsxE15lHQb5P9RAw47zHFb6QvEz25AzeJv8u7KZ16vRqjMBMAjXJQQq62uieufO6f0KGgoCKjZyjgB0C6J_I2DyW6kR0wi-I-azZVeTOnXJJl8Rr1pkvhKk88J7EMqu6S0r-TB6uziPzrA0N30beduj5U6ryeTwGEe2sOSwjErChZhAa0.2y-gnTMdJfhvV7wX6Yj0LG5YkOOeMEmsXL6mW3etajA&dib_tag=se&keywords=hc-sr04&qid=1710178436&sprefix=hc-sr04%2Caps%2C119&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) | 4 | Un sensore a ultrasuoni è un dispositivo che misura la distanza di un oggetto emettendo onde sonore **ultrasoniche** e converte il suono riflesso in un segnale elettrico. <ul><li>Alimentazione: 5V DC</li><li>Portata: 2 cm - 300 cm </li><li>Angolo effettivo: <15°</li></ul> |
| [`Sensori ad infrarossi`](https://www.amazon.it/AZDelivery-ultrasuoni-distanza-Raspberry-Abstandsensor/dp/B07D924JHT/ref=mp_s_a_1_5?dib=eyJ2IjoiMSJ9.N_u-ND_UNSKzILwTb_kxjlsZcEJNcU5Le3Hu39DGXwD1VZKRyrOdLBsll-pX1661BkCRVFys71-XLrlVqggrRjAohvOBZQRBgTgw6dQHC427BW-roSgnvJVozBauLSVE2-UaNJdcLvi581S5n_ZWF1OW3G5-9n3PBW2uPtV2ShYr_AD1vIiHsBmQy3Bxs5FrI4oLC_FK1V0thHQPpEed7A.yO1UcKvXtKMLtSVnJ6Q17CHAcejGBa83jLJXz3p3RHQ&dib_tag=se&keywords=Arduino%2BIr%2BSensor&qid=1710180504&sr=8-5&th=1) | 2 | Un sensore a infrarossi (IR) è un dispositivo che misura e rileva la radiazione infrarossa nell'ambiente circostante, utilizzato spesso come rilevatiore di **prossimità**. <ul><li>Alimentazione: 5 V DC</li><li>Portata: 2 cm - 30 cm </li><li>Angolo effettivo: <35°</li></ul> |
| [`LED`](https://www.amazon.it/AZDelivery-Emissione-Circolare-Emettitore-compatibile/dp/B08T1YGM8K/ref=sr_1_8?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2G25R9Q9KMV7M&dib=eyJ2IjoiMSJ9.Am2uI2a0USpWEEaWXZ90u194WS8WKSs1QZNDmJ6hj8_hYjaYFnkLlHD6lVWbkPfdHygL7TaWlO8mNwOuxr-frFUB0bavzQ94Ibj_YaqSa1V1ME1AiB6mrNFXCaHSsiUCMdFt-A4Ifhh9wUiVrrhQ3m4ttITdREQZFpaWtH6MWmbqbfQq1p714WPJp3kfOx224M1b20MTaLoXEOwoxqgkREE7-gup46SCvOQlz043GhnGBglaU4R-J4IT82WMzcNHRLVTaOKyj0LCsq0WJIhUfid-j2uI-_CjezbgR3MpGww.0WSwAdpsbW0cjDMWK-UAEMssRI6VXRBNlLM9M9BpgCs&dib_tag=se&keywords=led+arduino&qid=1711231790&sprefix=ledsarduino%2Caps%2C106&sr=8-8) | 9 | Un LED (*Light Emitting Diode*) è un dispositivo a semiconduttore che emette **luce** quando attraversato da una corrente elettrica. <ul><li>(4x) LED blu (*Vf* = 2,7 V; *If* = 20 mA)</li><li>(3x) LED bianchi (*Vf* = 2,7 V; *If* = 20 mA)</li><li>(1x) LED verde (*Vf* = 2,5 V; *If* = 20 mA)</li><li>(1x) LED rosso (*Vf* = 1,9 V; *If* = 20 mA)</li></ul>|
| [`Resistori`](https://www.amazon.it/AZDelivery-Resistenze-Resistori-Arduino-gratuito/dp/B07Q87JZ9G/ref=mp_s_a_1_3?crid=2TC9BVKNFDZ8E&dib=eyJ2IjoiMSJ9.m5BpWsNponXDu2NgiZft18byMuQH5acGxvlPhkBDKIAP6-y2xkoGZDoyxxVfIyDYEAg99g_jaLYLPw8QVpi4V4XCuJx9dncmhRd_uYIwo9uobWLQXDFQJ4iGopYZX5K_RucRwQR4Q-SBcYHL1jgJWOIpFCjRGIo-STIrgjKXDrMMtJ_gDsPfRLhde17dlA3fmogNdJBKoq52tJmEmCQ0lA.9eHZDTs0PXLqoFtuXdFetqe9rQbFbAhfiUGoJ44W2ts&dib_tag=se&keywords=azdelivery+resistor&qid=1711229207&sprefix=azdelivery+resistor+%2Caps%2C168&sr=8-3) | 10 | Un resistore è un componente elettronico che limita il flusso di corrente in un circuito, determinato dal suo valore di resistenza misurato in ohm, essenziale per **regolare** la quantità di corrente che attraversa il circuito e proteggere i componenti sensibili. <ul><li>(9x) Resistori da 470 Ω, 1/4 W</li><li>(1x) Resistori da 10 kΩ, 1/4 W</li></ul> |
| [`Fotoresistore`](https://www.amazon.it/AZDelivery-fotoresistenti-LDR5528-compatibili-Arduino/dp/B089YNCYG4/ref=sr_1_7?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2A3APBD8O8PY&dib=eyJ2IjoiMSJ9.QA9xJKurHImIT1lWJXxxdlnbVU5UKDHiJiSE8BfTa5shSX8N_5-MaEax9oqEEga5oNdL8Azt-5rqM3ElFDL3_B0r6F1qAQhCQTbHtBPYBOur-ZnERjDBQYsBogf_XU816SJLQFBg719l7WRvUNZGG7LiAoieR9oRcJriKK3CDxooxr4I4-moYNi1UXT8sbimDNixjAUhLv2dQ-H4lnygvw2ixt41P2KxyN8yO6ETdJ9fLiwU0NgUWKRUQkIr3XEbgrfC6cIpOYQ1T80aCICCmrM0zGWEunkuGV8vYIbvqds.Z_CgHc8fCiFFLbCQ0lHBB4iV51wunor6gzONEHCuHQs&dib_tag=se&keywords=photoresistor%2Bldr&qid=1711311437&sprefix=photoresistor%2Bld%2Caps%2C114&sr=8-7&th=1) | 1 | La fotoresistenza è un componente elettronico la cui resistenza è inversamente proporzionale alla quantità di luce che lo colpisce, il che lo rende adatto per la realizzazione di **luci crepuscolari**.|
| [`Servo motore SG90`](https://www.amazon.it/AZDelivery-Servomotore-compatibile-Elicottero-Arduino/dp/B07CYZK379/ref=sr_1_3_sspa?dib=eyJ2IjoiMSJ9.H5GMwpa4wNe8ulI-HmmzdcDht2QFTc48OwjhYYXIGgnF_nrgGONIOFU5ZTkcfWKfsql0zVMRrjnDoI1RDVFKbSKTAc8BVYbfDwlvx7gUBatWIHzP4UajWxboJIyJEdFu6NJDMSqDGAm6o207fv4AhQjXq59-yz3EZihzw5uH_0ZfiRZKMJWrpRNE2Z6cYtxTJxzI5ZC9MJeLHkQZb6y57rli0luWh3UFG2-qbtL_fFc-jzGfIWlapPriDetNoK6c0iaOqV0gYQqzO__K9Kn788wdh8yWWhfTVFtSnvadwKg.lN3SZuhmgmwKlqWWHE71rGuFKolFMLjj86eRxRc3MsI&dib_tag=se&keywords=arduino%2Bservo%2Bmotor&qid=1710865115&sr=8-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | Un servo motore è un dispositivo che converte un segnale di controllo in movimento **preciso e controllato**, comunemente utilizzato per il controllo di posizione in sistemi robotici e automazione industriale. <ul><li>Alimentazione: 4,8 - 6 V DC</li><li>Angolo di rotazione: 180 ° </li><li>Velocità: 0,1 s su 60°</li><li>Coppia: 2,5 kg/cm</li></ul> |
| [`Jumper wires`](https://www.amazon.it/gp/aw/d/B07KCFG5YX/?_encoding=UTF8&pd_rd_plhdr=t&aaxitk=de9838076b80169474b4678f431464e9&hsa_cr_id=3263644680502&qid=1711312198&sr=1-1-e0fa1fdd-d857-4087-adda-5bd576b25987&ref_=sbx_be_s_sparkle_lsi4d_asin_0_title&pd_rd_w=rpZDT&content-id=amzn1.sym.b580b30c-dd62-441e-ab95-5e749dbe7889%3Aamzn1.sym.b580b30c-dd62-441e-ab95-5e749dbe7889&pf_rd_p=b580b30c-dd62-441e-ab95-5e749dbe7889&pf_rd_r=JVVYGQ2GXAEZ3D0TW82Y&pd_rd_wg=FwLuU&pd_rd_r=161e4473-fa7a-4822-8c9c-0136839bec18&th=1) | ~100 | I jumper wires sono cavi elettrici **corti e flessibili** utilizzati per connettere componenti elettronici tra loro in modo rapido e senza saldatura. Si distinguono in *male-to-male*, *male-to-female* e *female-to-femnale* in base al tipo di estremità.|
| [`Powerbank 5V`](https://www.amazon.it/Powerbank-10400mAh-Caricabatterie-Portatile-Smartphone/dp/B07K1D2T5Z/ref=sr_1_5?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dib=eyJ2IjoiMSJ9.BIPnA8BKQhI8x_Uw5NNC-ug9yp0vTNsgVnbbs540ql1PzfFz5pwgr0mGNSesYeJonzmXacp1TX9ZhE54HvZrd02JtxGU_I9_gg2Qh0CFwFtPZcHX8Y-x8moMi_ZY8JzwNdqkyksxVemAAdcSNruSDtnZnticvLbntWML0MupUhjskF9LliKCn8-lI9b5xmm-aM1YmUO5QdJBMt2eY57vMuqlD9gqqqhOY_xsK5dqe8PoOnjdU8szz8SnYLFUxn9mbz4nRnuMUTmGxes365E4yqdYn0ZI_vLXLLmywo92t_M.7kuAkz54nGoahHmgf3QfydIKKFDvwwCP2OTcN0c8bns&dib_tag=se&keywords=power+bank+5+volt&qid=1713165582&sr=8-5) | 1 | Un powerbank è una fonte di energia **portatile** progettato per alimentare dispositivi **USB**, fornendo energia attraverso batterie interne ricaricabili. <li>Tensione: 5 V</li><li>Corrente (max): 3 A</li><li>Capacità: 10400 mAh</li> |
| [`Batterie AA`](https://www.amazon.it/GP-Batterie-alcaline-extra-Pack/dp/B07QLY7GJM/ref=sr_1_51?adgrpid=52877419152&dib=eyJ2IjoiMSJ9.7qd2mWgPWlRveGEJRbjXJNr_1e9RKYC6IRoJ2DMJVN8DdBdwJqCzqK73YUGTu7Fp6M8yQAk3qMl9dYuvGwGbMX7USwwgVBXJGIIQ5_AyID0oKvImWeARVVw5WJEQ0Yu4qGTWo3c7yk3QvBtwPNUi0jkd5V4RcMvFwj5okyh7y0IhIXa5eOPrGXhx_wAhMs2IetHvDGn6JOylqSXNwCbYjeA4Rl0DjkUd5rvQNbVtBsfFoNIqIcWG39teBqrWrV3nV3eMhC6yga41q2zkZMfY9eRJsmqzn6z_76V3YKGhaRc.uM6QNZjC_zp7i0GUddvcEFiaSM3V_ZWUb_dckQprSA4&dib_tag=se&hvadid=591172535230&hvdev=c&hvlocphy=20530&hvnetw=g&hvqmt=e&hvrand=7053405220002942603&hvtargid=kwd-297014870873&hydadcr=16358_2167162&keywords=batterie+aa&qid=1714133456&sr=8-51) | 4 | La batteria AA è una fonte di energia **portatile** di dimensione standard, comunemente utilizzata in dispositivi elettronici di piccole dimensioni. <li>Tensione: 1,5 V</li><li>Composizione: alcalina</li> |
| [`6V case per batterie AA`](https://www.amazon.it/GTIWUNG-Portabatterie-Batteries-Titolare-Batteria/dp/B07WJ3HFSP/ref=sr_1_4_sspa?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1H1FAUSVDY2ZO&dib=eyJ2IjoiMSJ9.VaIPkWXh1vEz2NWlzy-bskl9fVmzWq7qeBQ8_ApM4FPnZ8V06gFMpukyYOf0ioPXd84rmuTRhwcCTQ-VyXnU4EB3BAxMwPgJyKHS5BD2nhbk5AyTJEGofYvVUIhDMtfrEYWUxj76uI_8QnKTrhU6xVS8KeJ8W6aC3NxHL-sjlnikRBs7oRnvvSmNphDlNJrFtqXkM1Psx928dYTdv8xYIyf37HDewKhmBF5k6ltBX6ugh2mP0TILY5vQ6Vt7XLJGf1b0Tg2dlh3lrgPXofts5vrMIoWyVe_076TEcwlvY2E.PCfiGvevFAiXFAPFaMBk1aE8f2rlIRc813mSuyq8xkc&dib_tag=se&keywords=aa%2Bbattery%2Bholder&qid=1711374901&sprefix=aa%2Bbattery%2Bhgolder%2Caps%2C109&sr=8-4-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | Contenitore utilizzato per collegare 4 batterie AA in serie, generando una tensione totale di 6V. |

![Componenti del circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_components.png)

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Prototipo

Il progetto consiste in un prototipo di **sistema di parcheggio intelligente** implementato a livello comunale. Consiste in un modellino in scala di un percorso stradale comunale con **3 diverse zone parcheggio.**

### PARCHEGGIO **LIBERO** (strisce bianche)

- 2 *sensori a ultrasuoni* e 2 *LED*, spenti o accessi (rossi) in base allo stato del parcheggio (libero o occupato); il tempo minimo per il cambio di stato di uno slot è di 3’’ (1’ IRL)
- 2 slot (a L o a S)

### PARCHEGGIO A **ZONA DISCO (o a SOSTA BREVE)** (strisce bianche)

- 2 slot (a L o a S)
- 2 *sensori a ultrasuoni* e 2 *LED*, spenti o accessi (rossi) in base allo stato del parcheggio (libero o occupato); il tempo minimo per il cambio di stato di uno slot è di 3’’ (1’ IRL)
- Ogni slot è occupabile per un tempo massimo PRESTABILITO (es.: 1 ora + 15’ irl, 20’’ + 5’’ nel prototipo), superato quel tempo, Il LED inizia a lampeggiare fino a che lo slot non è liberato
- La zona disco è attiva solo da lunedì a sabato, dalle 8 alle 20.

### PARCHEGGIO A **PAGAMENTO** (strisce blu)

- 5 slot
- Gli slot NON prevedono sensori dedicati;
- Gli slot sono coperti da una tettoia ricoperta di pannelli fotovoltaici fittizi (come esempio di fonte di energia rinnovabile, implementato nel parcheggio che richiede più energia fra i tre)
- L’ingresso è a senso unico alternato (1), regolamentato da una sbarra (collegata ad un *servo motor*), da 2 *sensori IR* e da 2 *led* affiancati in funzione di semaforo (1 verde, attivo quando almeno uno slot è libero; 1 rosso, attivo solo quando tutti gli slot sono occupati)
- Processo di ingresso: l’utente accosta a fianco del sensore all’ingresso e viene verificato che gli slot non siano tutti occupati (se lo dovessero essere, visibile tramite il LED rosso, la sbarra non si aprirà); l’utente effettua il pagamento o ritira il ticket (3); la sbarra si apre e si chiude solo nel momento in cui il sensore oltre la sbarra è prima attivato e poi disattivato (passaggio completo dei veicolo); solo alla fine, il contatore dei parcheggi verrà incrementato di uno.
- Processo di uscita: l’utente accosta a fianco del sensore all’uscita; l’utente effettua il pagamento o ritira il ticket (3); la sbarra si apre e si chiude solo nel momento in cui il sensore oltre la sbarra è prima attivato e poi disattivato (passaggio completo dei veicolo); solo alla fine, il contatore dei parcheggi verrà decrementato di uno.
- Il parcheggio è dotato di un *fotoresistore* collegato a *2 (eventualmente 3) LED bianchi*, che si accendono in caso di scarsa luminosità esterna e sono posizionati sotto la tettoia, per illuminare il parcheggio (ulteriore giustifica del fatto che sia a pagamento)

Note:

1) *Indica che la viabilità è concessa in una sola direzione contemporaneamente; nel prototipo non si è integrata una zona d’uscita separata poiché la zona parcheggio è relativamente piccola e poiché non necessario ai fini dimostrativi del progetto.*

3) *OMESSO: il sistema di pagamento non è implementato nel prototipo perché estraneo ai fini dimostrativi del progetto, ma sarebbe necessariamente impiegato in una situazione reale (RICORDATELO).*

Il progetto prevede anche un applicazione (Arduino IoT Cloud) che consenta di verificare lo **stato dei parcheggi in tempo reale**, analizzare i **dati storici** sull’occupazione dei parcheggi e fornire informazioni relative alla distribuzione oraria dell’occupazione dello slot.

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Circuito

![Schema del circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_circuit_diagram.png)
![Circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_circuit.png)

Il circuito che gestisce il funzionamento del prototipo si occupa delle seguenti funzioni:
- **Alimentare** il microcontrollore Arduino e il servo motore.
- **Connettere** i vari sensori e attuatori ad Arduino in modo che possano essere **controllati** tramite codice.

Analizziamone ora le caratteristiche nello specifico.

## Alimentazione

### Arduino
Tra le varie opzioni di alimentazione per la scheda, si è scelto di utilizzare il **connettore USB-C® integrato**. È il metodo più comune, semplice e sicuro, poiché la tensione (*5 V*) e la corrente (*500 mA max*) sono **regolate e standardizzate** secondo le specifiche USB. Oltre all'Arduino, il connettore USB consente di alimentare anche i vari componenti connessi al pin *5v* della scheda.

Dato che la massima intensità di corrente concessa è di 500 mA, è stato necessario verificare che i dispositivi collegati ad Arduino non superassero complessivamente questo limite.

| Componente | Corrente massima | Quantità | Corrente totale massima
| --- | --- | ---| --- |
| `Sensore ad ultrasuoni` | ~5 mA | 4 | ~5 mA x 4 = **~20 mA** |
| `Sensore ad infrarossi` | ~5 mA | 2 | ~5 mA x 4 = **~10 mA** |
| `LED` | ~20 mA | 9 | 20 mA x 9 = **~180 mA** |

*(Il pin di controllo del servo motore e il fotoresistore consumano una quantità di corrente talmente bassa da potersi considerare trascurabile).*

La corrente totale massima è quindi pari a ~210 mA, abbondantemente entro il limite di 500 mA.                                         
**N.B.:** sebbene, a livello teorico, la massima corrente consumata da ciascun LED è pari a ~20 mA, nel circuito non supera mai gli 8 mA (per ragioni che saranno spiegate in seguito). Pertanto, la corrente massima (**~100 mA**) utilizzata risulta ancora minore.

### Servo motore
Il servo motore si distingue dagli altri componenti per il suo consumo di corrente **instabile**, caratterizzato da picchi di corrente elevati che potrebbero danneggiare il microcontrollore. Per questo motivo, è consigliabile alimentarlo tramite una fonte esterna, avente una tensione compresa tra 4,8 e 6 V. Di conseguenza, si è optato per l'utilizzo di **4 batterie AA** (1,5 V ciascuna) collegate in serie.

## Sensori
I sensori si occupano di rilevare alcune condizioni ambientali al fine di comunicarle al controllore.

### Sensori ad ultrasuoni
Un sensore ad ultrasuoni funziona emettendo impulsi sonori ad **alta frequenza**, al di fuori dell'udibile dall'orecchio umano, e misurando il tempo che impiega per questi impulsi a riflettersi da un oggetto e tornare al sensore. Conoscendo la velocità del suono nell'aria, il sensore calcola la distanza basandosi sul tempo impiegato dagli impulsi per viaggiare avanti e indietro, in base alla seguente formula:

$$distance =\frac{speed\ of\ sound \times time}{2}$$
  
![](https://cdn.shopify.com/s/files/1/0550/8091/0899/files/How-Ultrasonic-Sensors-Work_2_bbe85036-facc-4a57-a46d-c1e7f56312ba_600x600.gif?v=1677693349)

Il sensore è dotato di 4 connettori: *VCC* per l'alimentazione, *GND* per la terra, *ECHO* e *TRIG* per il controllo. I primi due sono collegati rispettivamente ai pin *5v* e *GND* dell'Arduino, attraverso la breadboard. I connettori *ECHO* e *TRIG* gestiscono l'invio e la ricezione degli ultrasuoni e possono essere collegati allo stesso pin GPIO (*General Purpose Input/Output*) del microcontrollore, poiché operano in modo alternato.

La scelta di questo sensore per il rilevamento dei parcheggi è motivata dalla sua **precisione** nelle misurazioni della distanza dei veicoli, consentendo una **facile regolazione** per adattarsi a vari tipi di parcheggio. Inoltre, non è influenzato da luce, fumo, polvere e caratteristiche delle superfici riflettenti (eccetto superfici morbide, che possono assorbire gli ultrasuoni anziché rifletterli; tuttavia, questo non è un problema nel contesto del rilevamento dei parcheggi).

### Sensori ad infrarossi attivo
Un sensore ad infrarossi attivo funziona emettendo un fascio di luce infrarossa e poi rilevando la sua riflessione. Quando un oggetto si trova nel percorso del fascio, la luce infrarossa viene riflessa verso il sensore, il quale rileva la presenza dell'oggetto. Questa variazione nella riflessione della luce è interpretata come la presenza di un oggetto davanti al sensore.

![](https://circuitdigest.com/sites/default/files/inlineimages/u4/IR-Sensor-Working.gif)

Il sensore dispone di 3 connettori: *VCC* per l'alimentazione, *GND* per la terra e *OUT* per il controllo.  Il collegamento ad Arduino è analogo a quello del sensore ad ultrasuoni.

La scelta di utilizzare questo sensore per la rilevazione dei veicoli all'accesso del parcheggio a pagamento è motivata dalla sua **affidabile** capacità di rilevare la presenza di un oggetto di fronte a sé, nonché dalla sua **facilità** di utilizzo. Tuttavia, a differenza del sensore ad ultrasuoni, non è in grado di fornire misurazioni precise, quindi non è raccomandato per il rilevamento dei parcheggi. È inoltre particolarmente sensibile alle condizioni di estrema luminosità, rendendolo inadatto per applicazioni esposte ad una forte luce solare.

La volontà di utilizzare due diverse tipologie di sensori nel prototipo deriva anche dalla volontà di effettuare un confronto tra i due, così da delineare i rispettivi **vantaggi e svantaggi**.

### Fotoresistenza

Il fotoresistore, pur non essendo un sensore vero e proprio ma una *resistenza*, costituisce l'ultimo componente di questa categoria. È un dispositivo elettronico che **modifica** la propria resistenza in base all'**intensità luminosa** a cui è esposto. Quando la luce colpisce il materiale fotosensibile all'interno del dispositivo, gli elettroni vengono eccitati, aumentando la conduttività del materiale e, di conseguenza, diminuendo la resistenza del fotoresistore. Questa variazione di resistenza viene sfruttata per controllare altri elementi del circuito elettronico, come, ad esempio, l'attivazione o la disattivazione di una luce crepuscolare in risposta ai cambiamenti di luminosità ambientale.

![](https://engineeringlearn.com/wp-content/uploads/2021/12/LDR.jpg)

Poiché i pin di Arduino non sono in grado di misurare direttamente una variazione di resistenza ma solo di tensione, il collegamento del fotoresistore avviene tramite un circuito noto come "***partitore di tensione***". Questo circuito è composto da due resistenze collegate in serie a una fonte di tensione. La tensione si distribuisce sulle diverse resistenze in base ai loro valori, secondo le regole delle *resistenze in serie* e alla *legge delle maglie di Kirchhoff*. Nel nostro caso, le due resistenze sono il fotoresistore (variabile) e un resistore da 10 kΩ (un valore standard per garantire una buona sensibilità e un basso consumo di corrente), mentre la fonte di tensione è il pin *5V* del microcontrollore.
Successivamente, un GPIO pin analogico di Arduino (in questo caso *A5*), è connesso in mezzo alle due resistenze. Trattandosi di un pin analogico, esso è in grado di leggere una gamma di valori anziché solo un valore digitale. Il valore di tensione misurato può essere interpretato attraverso il codice per determinare il livello di luminosità ed effettuare le azioni necessarie.

## Attuatori
Gli attuatori si occupano di convertire i segnali del microcontrollore in azioni fisiche.

### LED
Il circuito utilizza 9 LED, diodi a semiconduttore che emettono **luce** quando attraversati da corrente elettrica. Ciascun LED è controllato tramite un pin digitale GPIO di Arduino, con l'eccezione di 3 LED collegati a pin analogici, che possono funzionare anche come digitali (tuttavia tale flessibilità non vale al contrario, in quanto pin digitali non possono fungere da analogici). Nello specifico, ogni LED è dotato di un *anodo* (terminale positivo) connesso al pin della scheda e di un *catodo* (terminale negativo) collegato al *GND* del microcontrollore.

![](https://www.emanuelegenovese.it/wp-content/uploads/2018/03/LED-anatomia.png)

Ogni LED possiede 2 importanti proprietà:
- ***Caduta di tensione diretta** (Vf)*: tensione necessaria affinché possa fluire corrente attraverso il LED.
- ***Corrente diretta massima** (If)*: valore massimo di corrente che può attraversare il LED senza danneggiarlo. Nei LED utilizzati, equivale a **20 mA**.

Inoltre, ogni pin GPIO dell'*Arduino UNO R4 WiFi* ha un limite massimo di corrente che può essere assorbito da un dispositivo collegato senza danneggiare il pin, pari a **8 mA**. Quindi, per garantire che la corrente che scorre attraverso il LED sia inferiore a 8 mA, è necessario aggiungere un **resistore in serie** a ciascun LED. Per maggior sicurezza, si opta per una corrente ancora più ridotta, come **7 mA**.

Il valore idoneo della resistenza è stabilito dalla **prima legge di Ohm**:
> **"La differenza di potenziale ai capi di un resistore è uguale al prodotto della resistenza per l'intensità della corrente che lo attraversa.**

Definendo quindi *Vs* come tensione di alimentazione, pari a *5V* (standard erogato dai GPIO pin di Arduino), possiamo determinare il valore dei resistori in base alla seguente formula:
$$R=\frac{Vs - Vf}{If}$$

Possiamo dunque determinare il valore della resistenza per ogni colore di LED utilizzato.

| Colore del LED | Vf | If | Resistenza |
| --- | --- | ---| --- |
| `Blu` | 2,7 V | 7 mA | $$\frac{5,0 V - 2,7 V}{7 mA} = 328,6 Ω $$ |
| `Bianco` | 2,7 V | 7 mA | $$\frac{5,0 V - 2,7 V}{7 mA} = 328,6 Ω $$ |
| `Verde` | 2,5 V | 7 mA | $$\frac{5,0 V - 2,5 V}{7 mA} = 357,1 Ω $$ |
| `Rosso` | 1,9 V | 7 mA | $$\frac{5,0 V - 1,9 V}{7 mA} = 442,9 Ω $$ |

Dopo aver eseguito i calcoli e considerando la disponibilità del set di resistori, l'opzione migliore è utilizzare **un resistore da 470 Ω per ciascun LED**, in modo da assicurare che la corrente diretta attraverso ciascuno sia ben al di sotto del limite massimo di 8 mA.

### Servo motore
Un servo motore è un dispositivo, tipicamente di ridotta potenza, utilizzato per convertire un segnale di controllo in un **movimento preciso e controllato**. Questo processo è reso possibile grazie alla tecnica di modulazione chiamata PWM (Pulse Width Modulation)o. In sostanza, il segnale PWM consiste in una serie di impulsi elettrici con una frequenza costante, ma con la durata (o larghezza) di ciascun impulso variabile. Quando Arduino controlla il servomotore, utilizza la funzione analogWrite(pin, valore) per generare segnali PWM di diverse larghezze. Ad esempio, se si desidera spostare il servomotore in una determinata posizione, Arduino invia impulsi PWM con una larghezza proporzionale a quella posizione. La durata dell'impulso è proporzionale alla posizione desiderata del servomotore.

![](https://lastminuteengineers.com/wp-content/uploads/arduino/Servo-Motor-Working-Animation.gif)

Il servo motore possiede 3 connettori: *rosso* per l'alimentazione, *marrone* per la terra, *arancione* per il controllo. I primi due sono connessi al generatore da *6V*, mentre il cavo di controllo è collegato ad un GPIO PWM digitale, nello specifico al pin *D10*. 


-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Codice

Linguaggio: C++
Rimanda al codice, dove tutto è spiegato tramite commenti, altrimenti non finiresti più, eventualmente usa il codice anche durante la presentazione.
Al limite puoi descrivere il ruolo di ogni file.

-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------

# Collegamenti interdisciplinari

