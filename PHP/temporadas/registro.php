<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
    	<title>Gestion de Productos</title>
    	<?php
    	include_once("./scriptsPHP/temporadasFondo.php"); //le agregamos modularidad al sistema
    	include_once("./scriptsPHP/generadorDivsPropductos.php");
		 ?>
		 <meta  http-equiv="Content-type"   content="text/html; charset=UTF-8" >	
		<link type="text/css" rel="stylesheet" href="./estilos/disenoPrincipal.css" />
		<link type="text/css" rel="stylesheet" 
		href="./estilos/<?php echo $estaciones[$numeroEstacion]; ?>" />
		<link type="text/css" rel="stylesheet" href="./estilos/estiloGestionProductos.css" /> 
</head>
<body>
	
   			<?php
   			//incluimos el html que necesitamos
   			//haremos iframe que es algo que cambia de acuerdo a lo que seleccionamos con l aparte de ariba igual
   			include_once("./componentesHTML/encabezado1.php");
			?>
			<div id="GestionaProductos">
				<ul>
					<li><a title="Agregar un nuevo producto" href="./componentesHTML/agregar.php" target="despliegaDatos"></a>Agrergar Producto</li> <!--el target es para que lo ponag en el iframe, otra pago u otra cosa-->
					<li>Consultar Productos</li>
					<li>Modificar Producto</li>
					<li>Eliminar Producto</li>
				</ul>
			</div>
			<?php
   			//incluimos el html que necesitamos
   			include_once("./componentesHTML/imagenesCambiantes.php");
			?>
			<div id="EntradaDatos" name="EntradaDatos">
				<iframe name="despliegaDatos" id="despliegaDatos" title="despliega Datos" src="./componentesHTML/primera.php">
					
				</iframe>
			</div>
			
</body>
</html>