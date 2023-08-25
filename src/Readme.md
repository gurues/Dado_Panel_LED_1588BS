# DADO ELECTRÓNICO

## OBJETIVO

Con este proyecto quería "cacharrear" con paneles de matrices LED 8x8, modelo 1588BS, y crear un dado electrónico.

![Dado Electrónico](/Fotos/dado(1).jpg)
___

## DESCRIPCIÓN DEL PROYECTO

Este proyecto desarrolla un dado electrónico mediante un panel de matrices led de 8x8 modelo 1588BS. El control del dado se realiza con un Arduino Nano gestionando interrupciones que se producen al mover el dado. Las interrupciones son producidas por 2 sensores "tilt" conectados a los pines D2 y D3 que gestionan las interrupciones externas en este microcontrolador. Todo este proyecto está alimentado por una barería LIPO de 2500 mAh que se carga a través de un cargador TP4056. Para aumentar la tensión de la batería (~ 3,7 V) a la de alimentación del Arduino Nano (~7 V) uso un regulador DC-DC modelo MT3608.

El funcionamiento es el siguiente:

Al mover el dado, los detectores "tilt" actúan provocando una interrupción que hace que aleatoriamente pasados unos 2 segundos se muestre un valor del dado en el panel led. Este valor se mantiene fijo hasta que se vuelve a mover el dado y se produce una nueva interrupción que hace que se vuelva a calcular un nuevo valor del dado.

## AYUDA PARA SU REALIZACIÓN

En las carpetas: "3D", "Conexiones" y "Fotos", se comparten los diseños 3D del dado, sus conexiones así como una serie de fotos del resultado final.

## MATERIAL NECESARIO

* [Panel led 8x8 modelo 1588BS](https://es.aliexpress.com/item/1005002453688740.html?spm=a2g0o.productlist.main.23.1d8828e6ImNS5w&algo_pvid=8e1bf74c-b823-4220-a430-043531c02263&algo_exp_id=8e1bf74c-b823-4220-a430-043531c02263-11&pdp_npi=4%40dis%21EUR%212.23%212.23%21%21%212.38%21%21%40213fa03116927383646933153e010b%2112000020711731463%21sea%21ES%21889791699%21&curPageLogUid=ZGvrjGGsTZJX)
  
* [Arduino Nano](https://es.aliexpress.com/item/1005005594272986.html?spm=a2g0o.productlist.main.1.12924b2b64vLAr&algo_pvid=c6bb171c-3434-44db-8467-eda9e3668704&algo_exp_id=c6bb171c-3434-44db-8467-eda9e3668704-0&pdp_npi=4%40dis%21EUR%213.07%213.04%21%21%2123.55%21%21%40211b88ee16929794809176685e0487%2112000033682576632%21sea%21ES%21889791699%21&curPageLogUid=a3KGjiqJaSgr)

* [Interruptor](https://es.aliexpress.com/item/4000169106856.html?spm=a2g0o.order_list.order_list_main.228.21ef194dfQlmDd&gatewayAdapt=glo2esp)

* [Sensor "tilt"](https://es.aliexpress.com/item/1005002105161479.html?spm=a2g0o.order_list.order_list_main.91.21ef194dfQlmDd&gatewayAdapt=glo2esp)

* [Regulador de tensión MT3608](https://es.aliexpress.com/item/1005001636511712.html?spm=a2g0o.productlist.main.23.bad724c8b5zb3W&algo_pvid=a966e047-e2d6-4bf6-86ef-3ece2d862365&algo_exp_id=a966e047-e2d6-4bf6-86ef-3ece2d862365-11&pdp_npi=4%40dis%21EUR%210.54%210.43%21%21%210.57%21%21%40211b613916927379702357055e7447%2112000016918545272%21sea%21ES%21889791699%21&curPageLogUid=oDOmAQlTHaYj)
  
* [Cargador de batería TP4056](https://es.aliexpress.com/item/1005005771842912.html?spm=a2g0o.productlist.main.5.563553fbJbyfRD&algo_pvid=05be66cf-676c-4021-8280-1f3df19bc5ba&algo_exp_id=05be66cf-676c-4021-8280-1f3df19bc5ba-2&pdp_npi=4%40dis%21EUR%214.09%212.04%21%21%214.31%21%21%40211b88ef16929831510374782edab1%2112000034295324337%21sea%21ES%21889791699%21&curPageLogUid=7GX9s9CulkPL)

* [Batería LIPO 3.7 V](https://es.aliexpress.com/item/1005001310695209.html?spm=a2g0o.order_list.order_list_main.76.21ef194dfQlmDd&gatewayAdapt=glo2esp)

Este proyecto se puede realizar por menos de 20 euros si dispones de una impresora 3D.

## Realizado por gurues (gurues@3DO ~ Agosto 2023 ~ <ogurues@gmail.com>)
