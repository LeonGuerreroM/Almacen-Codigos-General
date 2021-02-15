<?php
	echo "recibido <br>";
	
		$nombreProducto=$_POST['NombreProducto'];
		$categ=$_POST['categorias'];
		$nombreTemporal=$_FILES['RutaImagen']['tmp_name'];
		$tamano=$_FILES['RutaImagen']['size'];
		$nombreReal=$_FILES['RutaImagen']['name'];
		$rutaImagenes="var/www/html/WebSabados/temporadas/img/productos";
		$destino=$rutaImagenes . $nombreReal;
		copy($nombreTemporal,$destino)or die("No se subio :'v");
		
		echo $nombreProducto."<br>"; 
		echo $categ."<br>";
		echo $nombreTemporal;
?>