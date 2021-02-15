<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
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
		 
		 
		 /*Generamos las opciones de categorias*/
		 
		 
		 $opcionCateg = "<div class='categ' id='opcion".
		 				$i ."'>
		                <p>Una opcion</p> </div>";
		 
		 
		 /*haciendo arreglo de imagenes y atributos (matriz)*/
		 
		 $fotosCategorias[1][1]="frio.jpg";
		 $fotosCategorias[1][2]="Bebidas Frias";
		 $fotosCategorias[1][3]="BebidasFrias.php";
		 $fotosCategorias[2][1]="caliente.jpg"; 
		 $fotosCategorias[2][2]="Bebidas Calientes";
		 $fotosCategorias[2][3]="BebidasCaliemtes.php";
		 $fotosCategorias[3][1]="comida.jpg";
		 $fotosCategorias[3][2]="Comida";
		 $fotosCategorias[3][3]="Comida.php";
		 $fotosCategorias[4][1]="solicitados.jpg";
		 $fotosCategorias[4][2]="Mas Solicitados";
		 $fotosCategorias[4][3]="Solicitados.php";
		 
		 
		 /*definimos los datos de los productos que se utilizan en las promociones
		  contenedro 1-> el mas vendido
		  * contenedor 2 ->el menos vendido
		  * contenedor 3 ->el de mayor precios
		  * contenedor 4 ->el de menor precio
		  * calve|nombre|descripcion|categoria|ingredientes|costo|porcion|imagen|ventas
		  * ---------------------------------------------------------------------------
		  * 0    |1      |2         | 3       |4           |5    | 6     |7     |8
		  * los arreglos pueden ser de indices combinados. En un solo arreglo pueden ser 1 y el siguiente de indice a y el otro de 1.5 y hasta true
		  * por lo tanto para un multidimensuional puede ser tambien combinados
		  * 
		  * 
		  * Practicamente haremos una tabla de BD
		  */
		 $productos[1]['clave']="F001";
		 $productos[1]['nombre']="Frappe de fresa";
		 $productos[1]['decripcion']="Bebida fria hecha de leche con fresa";
		 $productos[1]['categoria']="Frias";
		 $productos[1]['ingredientes']="Leche, yogurt, fresas, azucar";
		 $productos[1]['costo']=71;
		 $productos[1]['porcion']="vaso";
		 $productos[1]['imagen']="productos/frapeFresa.jpg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[1]['ventas']=10;
		 
		 $productos[2]['clave']="F002";
		 $productos[2]['nombre']="Frape Frapuccino";
		 $productos[2]['decripcion']="Bebida fria hecha de leche y cafe";
		 $productos[2]['categoria']="Frias";
		 $productos[2]['ingredientes']="Leche, cafe, hielo";
		 $productos[2]['costo']=250;
		 $productos[2]['porcion']="vaso";
		 $productos[2]['imagen']="productos/frapuccino.jpg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[2]['ventas']=50;
		 
		 $productos[3]['clave']="H001";
		 $productos[3]['nombre']="Americano";
		 $productos[3]['decripcion']="Cafe comun";
		 $productos[3]['categoria']="Calientes";
		 $productos[3]['ingredientes']="Agua, cafe, azucar";
		 $productos[3]['costo']=40;
		 $productos[3]['porcion']="taza";
		 $productos[3]['imagen']="productos/americano.jpg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[3]['ventas']=100;
		 
		 $productos[4]['clave']="C005";
		 $productos[4]['nombre']="Panini";
		 $productos[4]['decripcion']="Pan de diversos ingredientes";
		 $productos[4]['categoria']="Comida";
		 $productos[4]['ingredientes']="Pan, carne, verduras, aderezos";
		 $productos[4]['costo']=150;
		 $productos[4]['porcion']="Pieza";
		 $productos[4]['imagen']="productos/panini.jpg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[4]['ventas']=150;
		 
		 $productos[5]['clave']="P006";
		 $productos[5]['nombre']="Muffin";
		 $productos[5]['decripcion']="Pan con diferentes sabores";
		 $productos[5]['categoria']="Postres";
		 $productos[5]['ingredientes']="Pan, agregados";
		 $productos[5]['costo']=50;
		 $productos[5]['porcion']="Pieza";
		 $productos[5]['imagen']="productos/muffin.jpeg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[5]['ventas']=19;
		 
		 $productos[6]['clave']="H004";
		 $productos[6]['nombre']="Te";
		 $productos[6]['decripcion']="Infusiones";
		 $productos[6]['categoria']="Calientes";
		 $productos[6]['ingredientes']="Agua, infusion";
		 $productos[6]['costo']=70;
		 $productos[6]['porcion']="Vaso";
		 $productos[6]['imagen']="productos/te.jpeg"; //puedes hacer qu etome cierta carpeta desde la variable ya si abajo solo pones la carpeta que contiene a la carpeta que tienes aqui
		 $productos[6]['ventas']=130;
		 
		 
		 
		 
		 
		 function menosVendido($arregloCachado){
		 	for ($i=1; $i <=6; $i++) {
   						$menosVendido[$i]=$arregloCachado[$i]['ventas']; //pasa del bidimensional al dimensional, porque va guardando los de la posicion i pero siempre en la tupla de ventas
						 
					   }
					sort($menosVendido); 
					
					$tamano=count($menosVendido);
					for ($i=1; $i <=$tamano ; $i++) { //porque ese arreglo se emepezo desde el 0, asi que como son 6 elementos, tiene subindices del 0 al 5 
						if($arregloCachado[$i]['ventas'] == $menosVendido[0]){ //si el producto que estoy evaluando algo dentro de i arreglo de productos es igual a la ultima posicion de mi arreglo de numeros ya ordenados de menior a mayor, imprime
							//echo "EL registro mayor es: ". $productos[$i]['nombre'];
							$productoMenosVentas=$i; //porque la n que esta actuando en este momento es la mas grande pues logro entrar a la condicion, asi ya tenemmos la $i del arreglo productos que es el de las mayores ventas x,[ventas]
						}
					}
									
			
			return $productoMenosVentas;
   					
		 }


		function creadorDivs($id, $clase, $urlProducto, $nombreProducto, $imagen){
			echo "<div id='".
			$id.
			"' name='".
			$id.
			"'class='".
			$clase.
			"'><a href='".
			$urlProducto.
			"'target='-blank' title='".
			$nombreProducto.
			"'><img src='./img/".
			$imagen.
			"'alt='Imagen del producto title='".
			$nombreProducto.
			"'/> </a> </div>"
			;
			
			return 0;
		}
		 
		 
		function mayorPrecio($arregloCachado){	
			
		 	for ($i=1; $i <=6; $i++) {
   						$masCaro[$i]=$arregloCachado[$i]['costo']; 
					   }
			
					
					sort($masCaro); 
					
					$tamano=count($masCaro);
					
					
					for ($i=1; $i <=6; $i++) {
						
						if($arregloCachado[$i]['costo'] == $masCaro[$tamano-1]){ 
							$productoMasCaro=$i; 
						}
					}
									
			
			return $productoMasCaro;
   					
		 }
		
		
		function nuevos($arregloCachado){
			$contador=count($arregloCachado);
			return $contador;
   					
		 }
		
		function menorPrecio($arregloCachado){
		 	for ($i=1; $i <=6; $i++) {
   						$masBarato[$i]=$arregloCachado[$i]['costo']; 
					   }
					
					sort($masBarato); 
					
					$tamano=count($masBarato);
					for ($i=1; $i <=$tamano ; $i++) { 
						if($arregloCachado[$i]['costo'] == $masBarato[0]){ 
							$productoMasBarato=$i; 
						}
					}
									
			
			return $productoMasBarato;
   					
		 }
		 
		 
    	?>
        <meta  http-equiv="Content-type"   content="text/html; charset=UTF-8" >	
		<link type="text/css" rel="stylesheet" href="./estilos/disenoPrincipal.css" />
		<link type="text/css" rel="stylesheet" 
		href="./estilos/<?php echo $estaciones[$numeroEstacion]; ?>" />
    </head>
   	<body>
   		<div id="contPrincipal">
   			<!--inicio del encabezado-->
   			<div id="encabezado">
   				<div id="logoEmpresa">
   				<p>	logo</p>
   			</div>
   			<div id="redesSociales">
   				<p>redes Sociales</p>
   			</div>
   			</div>
   			
   			
   			<div id="menuPrincipal">
   			<ul id="opcionesMenu">
   				<li>Inicio</li>
   				<li>Conocenos</li>
   				<li>Productos</li>
   				<li>Promociones</li>
   				<li>Ubicacion</li>
   				<li><a href="./registro.php" title="Gestionar Productos" target="blank">Registro</a></li>
   			</ul>
   			</div>
   			<div id="galeria">
   				<img id="fotoGaleria" src="./img/<?php echo $fotosGalRandom[$aleatoria]; ?>" alt="imagen de cafe con libro" title="Lectura con cafe"/>
   			</div>
   			<div id="categorias" name="categorias">
   				<?php
   				//cuendo lo haces es [i][1 2 0 3 siempre] porque en 1 2 3 tiemne almacenado los mismos tipos de datos (descripciones y enlaces) solo ponemos la referencia de la imagen y con eso ya es suficiente porque jalara los elementos 1 2 y 3 de esa imagen que es como la llave principal o general siemopre
   				for($i=1;$i<=4;$i++){
   					echo "<div class='categ' id='opcion".
		 			$i ."'>
		 			<a href='./".
		 			$fotosCategorias[$i][3].
		 			"'> <img class='imagen' src='./img/".
		            $fotosCategorias[$i][1]. //que la variable aparezca fuera de la cadena para que funcione cuando use arreglos en especial de n dimensiones
		            "' alt='imagen de categoria'".
		            "title='".
		            $fotosCategorias[$i][2].
		            "'/> 
		            </a>
		            </div>";
   				}
 
   				?>
   			</div>
   			<div id="Promociones" name="Promociones">
   				<div id="ProductoMasVendido" name="ProductoMasVendido" class="categoriaPromociones">
   					<?php 
   					
   					for ($i=1; $i <=6; $i++) {
   						$masVendido[$i]=$productos[$i]['ventas']; //pasa del bidimensional al dimensional, porque va guardando los de la posicion i pero siempre en la tupla de ventas
						 
					   }
					sort($masVendido); 
				
					/*foreach ($masVendido as $Identificador => $valor) { //este es un for para recorrer un elemento del que nosabemos la longitud
						echo $identificador . "tiene el valor" . $valor. "<br>"; //pone de 0 al infinito igual a los valores que va recorriendo
					}*/
					
					//Buscamos el mayor. EL ultimo elemento
					//se cuenta desde 0
					$tamano=count($masVendido);
					for ($i=1; $i <=$tamano ; $i++) { //porque ese arreglo se emepezo desde el 0, asi que como son 6 elementos, tiene subindices del 0 al 5 
						if($productos[$i]['ventas'] == $masVendido[$tamano-1]){ //si el producto que estoy evaluando algo dentro de i arreglo de productos es igual a la ultima posicion de mi arreglo de numeros ya ordenados de menior a mayor, imprime
							//echo "EL registro mayor es: ". $productos[$i]['nombre'];
							$productoMasVentas=$i; //porque la n que esta actuando en este momento es la mas grande pues logro entrar a la condicion, asi ya tenemmos la $i del arreglo productos que es el de las mayores ventas x,[ventas]
							//solo para que arroje indice
						}
					}
					//echo $mayor, "<br>";
   					echo "<img src='./img/".
   					$productos[$productoMasVentas]['imagen'].
   					"' alt='imagen de frappe' title='".
   					$productos[$productoMasVentas]['nombre'].
   					"'/>";
					?>
   				</div>
   				
   					<?php
   					$menosV=menosVendido($productos);
					$masC=mayorPrecio($productos);
					$masB=menorPrecio($productos);	
					$novedad=nuevos($productos);
							
   					?>
   					
   				<?php
   				creadorDivs("ProductoMenosVendido", "categoriaPromociones", "F001.php", $productos[$menosV]['nombre'], $productos[$menosV]['imagen']);
   				creadorDivs("ProductoMayorCosto", "categoriaPromociones", "C005.php", $productos[$masC]['nombre'], $productos[$masC]['imagen']);
				creadorDivs("ProductoMenorCosto", "categoriaPromociones", "H001.php", $productos[$masB]['nombre'], $productos[$masB]['imagen']);
				creadorDivs("Novedad", "categoriaPromociones", "P006.php", $productos[$novedad]['nombre'], $productos[$novedad]['imagen']);
				?>
   				
   			</div>
   			
   			
   			<p>recurso web con cafe</p>
   		</div>
   		
   		
   		
   		
   		
   	</body>
   	</html>