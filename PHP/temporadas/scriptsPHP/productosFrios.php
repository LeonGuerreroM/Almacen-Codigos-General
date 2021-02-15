<?php


include_once("./scriptsPHP/arregloProductos.php");
include_once("./scriptsPHP/generadorDivsProductos.php");

?>

<div id="descripcionFrapuccino" name="datosProducto" class="renglonProducto">
	<div id="nombreFrapp">
			<?php
			nombreDivProducto(2, $productos, "describeProducto");
			?>
	</div>
	<div id="imagenFrapp">
		<?php
			creadorDivs("Frapuccino",
			"describeProducto",
			$productos[2]['clave'],
			$productos[2]['nombre'],
			$productos[2]['imagen']);
			?>
	</div>
	<div id="costoFrapp">
		<p>Precio: $<?php costoDivProducto(2, $productos, "describeProducto"); ?></p>
		
	</div>
</div>
