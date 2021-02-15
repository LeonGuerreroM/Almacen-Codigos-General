<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
    	<?php
    	include_once("./scriptsPHP/temporadasFondo.php"); //le agregamos modularidad al sistema
    	include_once("./scriptsPHP/generadorDivsPropductos.php");
    	?>
    	
    	
    	
    	
    	<meta  http-equiv="Content-type"   content="text/html; charset=UTF-8" >	
		<link type="text/css" rel="stylesheet" href="./estilos/disenoPrincipal.css" />
		<link type="text/css" rel="stylesheet" href="./estilos/<?php echo $estaciones[$numeroEstacion]; ?>" />
		<link type="text/css" rel="stylesheet" href="./estilos/estilosCategorias.css" />
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
   				<li>Registro</li>
   			</ul>
   			</div>
   			<div id="descripcionProductos" class="descripcionProductos">
   				<div id="nombreCategoria" name="nombreCategoria">
   					<h1>Bibidas Frías</h1>
   				</div>
   			</div>
			<?php
			include_once("./scriptsPHP/productosFrios.php");
			?>
	
	
	
</body>
</html>