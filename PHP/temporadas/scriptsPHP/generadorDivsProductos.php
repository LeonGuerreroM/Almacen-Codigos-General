<?php
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

		
		
function nombreDivProducto($indice, $productos, $clase){
	echo "<div id='nombre".
			$productos[$indice]['clave'].
			"'class='".
			$clase. " '>".
			"<label>".
			$productos[$indice]['nombre'].
			"<label>".
			"</div>";
	
			
			return 0;
}
function costoDivProducto($indice, $productos, $clase){
	echo "<div id='precio".
			$productos[$indice]['clave'].
			" '>".
			"<label>".
			$productos[$indice]['costo'].
			"<label>".
			"</div>";
	
			
			return 0;
}
		
		?>
		
