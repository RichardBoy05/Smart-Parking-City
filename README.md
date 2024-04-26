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
7. [Domande, suggerimenti e bug fixes](#domande-suggerimenti-e-bug-fixes)
   
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

# Materiali

## Modellino
- Scatola di cartone 62,0 x 44,0 cm
- Cartoncino (vari elementi 3D)
- Nastro adesivo e biadesivo
- 
## Mappa
![Mappa](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/map/smart_parking_city_map.png)

## Componenti del circuito
| Componente | Quantità | Descrizione |
| --- | --- | --- |
| [`Arduino UNO R4 WiFi`](https://docs.arduino.cc/hardware/uno-r4-wifi/) | 1 | L'Arduino Uno R4 Wifi è una scheda di sviluppo *open-source* che combina le funzionalità dell'Arduino Uno classico con la connettività WiFi integrata, consentendo agli utenti di creare progetti interattivi e connessi alla rete in modo semplice e versatile. |
| [`Breadboard`](https://www.amazon.it/AZDelivery-Breadboard-830-Arduino-Raspberry/dp/B07K8PQ4B5/ref=sr_1_2_sspa?crid=1LMAFIJE2TP5X&dib=eyJ2IjoiMSJ9.xi5AD3br6MkhFSnelneIz7280DzKo1UPIgHXXQxS0vDi-8Bj8_KMO0Ft7mOEqn_c4DgwRgptPgED-dbL794yeQGaXmW2_qVZUJwOZC9koeBdMlCEWO5zqT9bsy9L2nphxe2txNQFNUz6pkFSZn8p07Ap2cJVg1HmHG6fYz52zx-99Eig9D_CrKX9PWKCvcmJHxeDd1Yq5woqp8RimPIKu8p5l6XgSiEbDgoBknKcrwAFMY1qN1KmEPWghXLIkrgJr-bDWcngQiwzBPV1lfq6UnJalqQV_hPRmeFzyHoQ3pc.CoHS3PYbmqBx3LB_7yP7nYr01mM75NqVi_AmuokDvlI&dib_tag=se&keywords=breadboard%2Bazdelivery&qid=1711213155&sprefix=breadboard%2Baz%2Caps%2C111&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`Sensore ad ultrasuoni HC-SR04`](https://www.amazon.it/HC-SR04-Misuratore-Distanze-Ultrasuoni-Ultrasonic/dp/B01COSN7O6/ref=sr_1_1_sspa?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=30NWWH1A2DL14&dib=eyJ2IjoiMSJ9.YPGfdw-5BDSrtfbP8kv-6aGGle4kgcSXSrlzpcqGoPsfcnfizPwGRtIYfIKsq8itrG6JeKxwGq2DwFn2DMf3zIOc5y_8k_RRBCZPZdmaIo9Gq8HodidfIYzK55jsxE15lHQb5P9RAw47zHFb6QvEz25AzeJv8u7KZ16vRqjMBMAjXJQQq62uieufO6f0KGgoCKjZyjgB0C6J_I2DyW6kR0wi-I-azZVeTOnXJJl8Rr1pkvhKk88J7EMqu6S0r-TB6uziPzrA0N30beduj5U6ryeTwGEe2sOSwjErChZhAa0.2y-gnTMdJfhvV7wX6Yj0LG5YkOOeMEmsXL6mW3etajA&dib_tag=se&keywords=hc-sr04&qid=1710178436&sprefix=hc-sr04%2Caps%2C119&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) | 4 | sssssssssssssssssssssssssssssssssssssss |
| [`Sensore ad infrarossi`](https://www.amazon.it/AZDelivery-ultrasuoni-distanza-Raspberry-Abstandsensor/dp/B07D924JHT/ref=mp_s_a_1_5?dib=eyJ2IjoiMSJ9.N_u-ND_UNSKzILwTb_kxjlsZcEJNcU5Le3Hu39DGXwD1VZKRyrOdLBsll-pX1661BkCRVFys71-XLrlVqggrRjAohvOBZQRBgTgw6dQHC427BW-roSgnvJVozBauLSVE2-UaNJdcLvi581S5n_ZWF1OW3G5-9n3PBW2uPtV2ShYr_AD1vIiHsBmQy3Bxs5FrI4oLC_FK1V0thHQPpEed7A.yO1UcKvXtKMLtSVnJ6Q17CHAcejGBa83jLJXz3p3RHQ&dib_tag=se&keywords=Arduino%2BIr%2BSensor&qid=1710180504&sr=8-5&th=1) | 2 | sssssssssssssssssssssssssssssssssssssss |
| [`LED`](https://www.amazon.it/AZDelivery-Emissione-Circolare-Emettitore-compatibile/dp/B08T1YGM8K/ref=sr_1_8?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2G25R9Q9KMV7M&dib=eyJ2IjoiMSJ9.Am2uI2a0USpWEEaWXZ90u194WS8WKSs1QZNDmJ6hj8_hYjaYFnkLlHD6lVWbkPfdHygL7TaWlO8mNwOuxr-frFUB0bavzQ94Ibj_YaqSa1V1ME1AiB6mrNFXCaHSsiUCMdFt-A4Ifhh9wUiVrrhQ3m4ttITdREQZFpaWtH6MWmbqbfQq1p714WPJp3kfOx224M1b20MTaLoXEOwoxqgkREE7-gup46SCvOQlz043GhnGBglaU4R-J4IT82WMzcNHRLVTaOKyj0LCsq0WJIhUfid-j2uI-_CjezbgR3MpGww.0WSwAdpsbW0cjDMWK-UAEMssRI6VXRBNlLM9M9BpgCs&dib_tag=se&keywords=led+arduino&qid=1711231790&sprefix=ledsarduino%2Caps%2C106&sr=8-8) | 9 | <ul><li>(9x) 470 Ω, 1/4 W</li><li>(1x) 10kΩ, 1/4W</li></ul> |
| [`Resistori`](https://www.amazon.it/AZDelivery-Resistenze-Resistori-Arduino-gratuito/dp/B07Q87JZ9G/ref=mp_s_a_1_3?crid=2TC9BVKNFDZ8E&dib=eyJ2IjoiMSJ9.m5BpWsNponXDu2NgiZft18byMuQH5acGxvlPhkBDKIAP6-y2xkoGZDoyxxVfIyDYEAg99g_jaLYLPw8QVpi4V4XCuJx9dncmhRd_uYIwo9uobWLQXDFQJ4iGopYZX5K_RucRwQR4Q-SBcYHL1jgJWOIpFCjRGIo-STIrgjKXDrMMtJ_gDsPfRLhde17dlA3fmogNdJBKoq52tJmEmCQ0lA.9eHZDTs0PXLqoFtuXdFetqe9rQbFbAhfiUGoJ44W2ts&dib_tag=se&keywords=azdelivery+resistor&qid=1711229207&sprefix=azdelivery+resistor+%2Caps%2C168&sr=8-3) | 10 | <ul><li>, 1/4 W</li><li>(1x) 10kΩ, 1/4W</li></ul> |
| [`Fotoresistore`](https://www.amazon.it/AZDelivery-fotoresistenti-LDR5528-compatibili-Arduino/dp/B089YNCYG4/ref=sr_1_7?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2A3APBD8O8PY&dib=eyJ2IjoiMSJ9.QA9xJKurHImIT1lWJXxxdlnbVU5UKDHiJiSE8BfTa5shSX8N_5-MaEax9oqEEga5oNdL8Azt-5rqM3ElFDL3_B0r6F1qAQhCQTbHtBPYBOur-ZnERjDBQYsBogf_XU816SJLQFBg719l7WRvUNZGG7LiAoieR9oRcJriKK3CDxooxr4I4-moYNi1UXT8sbimDNixjAUhLv2dQ-H4lnygvw2ixt41P2KxyN8yO6ETdJ9fLiwU0NgUWKRUQkIr3XEbgrfC6cIpOYQ1T80aCICCmrM0zGWEunkuGV8vYIbvqds.Z_CgHc8fCiFFLbCQ0lHBB4iV51wunor6gzONEHCuHQs&dib_tag=se&keywords=photoresistor%2Bldr&qid=1711311437&sprefix=photoresistor%2Bld%2Caps%2C114&sr=8-7&th=1) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`Servo motore`](https://www.amazon.it/AZDelivery-Servomotore-compatibile-Elicottero-Arduino/dp/B07CYZK379/ref=sr_1_3_sspa?dib=eyJ2IjoiMSJ9.H5GMwpa4wNe8ulI-HmmzdcDht2QFTc48OwjhYYXIGgnF_nrgGONIOFU5ZTkcfWKfsql0zVMRrjnDoI1RDVFKbSKTAc8BVYbfDwlvx7gUBatWIHzP4UajWxboJIyJEdFu6NJDMSqDGAm6o207fv4AhQjXq59-yz3EZihzw5uH_0ZfiRZKMJWrpRNE2Z6cYtxTJxzI5ZC9MJeLHkQZb6y57rli0luWh3UFG2-qbtL_fFc-jzGfIWlapPriDetNoK6c0iaOqV0gYQqzO__K9Kn788wdh8yWWhfTVFtSnvadwKg.lN3SZuhmgmwKlqWWHE71rGuFKolFMLjj86eRxRc3MsI&dib_tag=se&keywords=arduino%2Bservo%2Bmotor&qid=1710865115&sr=8-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`Jumper wires`](https://www.amazon.it/gp/aw/d/B07KCFG5YX/?_encoding=UTF8&pd_rd_plhdr=t&aaxitk=de9838076b80169474b4678f431464e9&hsa_cr_id=3263644680502&qid=1711312198&sr=1-1-e0fa1fdd-d857-4087-adda-5bd576b25987&ref_=sbx_be_s_sparkle_lsi4d_asin_0_title&pd_rd_w=rpZDT&content-id=amzn1.sym.b580b30c-dd62-441e-ab95-5e749dbe7889%3Aamzn1.sym.b580b30c-dd62-441e-ab95-5e749dbe7889&pf_rd_p=b580b30c-dd62-441e-ab95-5e749dbe7889&pf_rd_r=JVVYGQ2GXAEZ3D0TW82Y&pd_rd_wg=FwLuU&pd_rd_r=161e4473-fa7a-4822-8c9c-0136839bec18&th=1) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`Batterie AA`](https://www.amazon.it/GP-Batterie-alcaline-extra-Pack/dp/B07QLY7GJM/ref=sr_1_51?adgrpid=52877419152&dib=eyJ2IjoiMSJ9.7qd2mWgPWlRveGEJRbjXJNr_1e9RKYC6IRoJ2DMJVN8DdBdwJqCzqK73YUGTu7Fp6M8yQAk3qMl9dYuvGwGbMX7USwwgVBXJGIIQ5_AyID0oKvImWeARVVw5WJEQ0Yu4qGTWo3c7yk3QvBtwPNUi0jkd5V4RcMvFwj5okyh7y0IhIXa5eOPrGXhx_wAhMs2IetHvDGn6JOylqSXNwCbYjeA4Rl0DjkUd5rvQNbVtBsfFoNIqIcWG39teBqrWrV3nV3eMhC6yga41q2zkZMfY9eRJsmqzn6z_76V3YKGhaRc.uM6QNZjC_zp7i0GUddvcEFiaSM3V_ZWUb_dckQprSA4&dib_tag=se&hvadid=591172535230&hvdev=c&hvlocphy=20530&hvnetw=g&hvqmt=e&hvrand=7053405220002942603&hvtargid=kwd-297014870873&hydadcr=16358_2167162&keywords=batterie+aa&qid=1714133456&sr=8-51) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`6V case per batterie AA`](https://www.amazon.it/GTIWUNG-Portabatterie-Batteries-Titolare-Batteria/dp/B07WJ3HFSP/ref=sr_1_4_sspa?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1H1FAUSVDY2ZO&dib=eyJ2IjoiMSJ9.VaIPkWXh1vEz2NWlzy-bskl9fVmzWq7qeBQ8_ApM4FPnZ8V06gFMpukyYOf0ioPXd84rmuTRhwcCTQ-VyXnU4EB3BAxMwPgJyKHS5BD2nhbk5AyTJEGofYvVUIhDMtfrEYWUxj76uI_8QnKTrhU6xVS8KeJ8W6aC3NxHL-sjlnikRBs7oRnvvSmNphDlNJrFtqXkM1Psx928dYTdv8xYIyf37HDewKhmBF5k6ltBX6ugh2mP0TILY5vQ6Vt7XLJGf1b0Tg2dlh3lrgPXofts5vrMIoWyVe_076TEcwlvY2E.PCfiGvevFAiXFAPFaMBk1aE8f2rlIRc813mSuyq8xkc&dib_tag=se&keywords=aa%2Bbattery%2Bholder&qid=1711374901&sprefix=aa%2Bbattery%2Bhgolder%2Caps%2C109&sr=8-4-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) | 1 | sssssssssssssssssssssssssssssssssssssss |
| [`Powerbank 5V`](https://www.amazon.it/Powerbank-10400mAh-Caricabatterie-Portatile-Smartphone/dp/B07K1D2T5Z/ref=sr_1_5?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dib=eyJ2IjoiMSJ9.BIPnA8BKQhI8x_Uw5NNC-ug9yp0vTNsgVnbbs540ql1PzfFz5pwgr0mGNSesYeJonzmXacp1TX9ZhE54HvZrd02JtxGU_I9_gg2Qh0CFwFtPZcHX8Y-x8moMi_ZY8JzwNdqkyksxVemAAdcSNruSDtnZnticvLbntWML0MupUhjskF9LliKCn8-lI9b5xmm-aM1YmUO5QdJBMt2eY57vMuqlD9gqqqhOY_xsK5dqe8PoOnjdU8szz8SnYLFUxn9mbz4nRnuMUTmGxes365E4yqdYn0ZI_vLXLLmywo92t_M.7kuAkz54nGoahHmgf3QfydIKKFDvwwCP2OTcN0c8bns&dib_tag=se&keywords=power+bank+5+volt&qid=1713165582&sr=8-5) | 1 | sssssssssssssssssssssssssssssssssssssss |

![Componenti del circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_components.png)

# Circuito
![Schema del circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_circuit_diagram.png)
![Circuito](https://github.com/RichardBoy05/Smart-Parking-City/blob/main/resources/circuit/smart_parking_city_circuit.png)


