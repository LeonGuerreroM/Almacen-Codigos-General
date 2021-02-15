<?php
    	/*un recurso que cambia su diseño dependiendo de la temporada*/
    	$estaciones[1]="primaveraColores.css";
    	$estaciones[2]="veranoCOlores.css";
    	$estaciones[3]="OtonoColores.css";
    	$estaciones[4]="inviernoCOlores.css";
		$mesActual=date(n); //almacenamos un numero del 1 al 12
		
		if(($mesActual==3)||($mesActual==4)||($mesActual==5)){
			$numeroEstacion=1;
		}
		elseif(($mesActual==6)||($mesActual==7)||($mesActual==8)){
			$numeroEstacion=2;
		}
		elseif(($mesActual==9)||($mesActual==10)||($mesActual==11)){
			$numeroEstacion=3;
		}
		elseif(($mesActual==12)||($mesActual==1)||($mesActual==2)){
			$numeroEstacion=4;
		}else{
			$numeroEstacion=4;
		}
		
		/*en un for se pueden inicializar dos valores separados por comas ,,,
		 * for(i=5,j=4) y asi para todo
		 */
		
		/*
		 * Imagen que cambia cada que se carga la pagina
		 */	
		 
		 $fotosGalRandom[1]="cafeO.jpg";
		 $fotosGalRandom[2]="cafecito.jpg";
		 $fotosGalRandom[3]="lapcafe.jpg";
		 $fotosGalRandom[4]="librecafe.jpeg";
		 
		 $aleatoria=rand(1,4);
?>