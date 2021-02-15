<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html lang="es">
    <head>
    	<title>Agrega producto</title>
	</head>
	
	
	<body>
		<form id="AgregaProducto" name="AgregarProducto" method="post" enctype="multipart/form-data" action="./respuesta.php"> 
			<h3>Agregar Producto</h3>
			<h4>Introduce los datos que se solicitan</h4>
			
			<label>Nombre del Producto</label>
			<input type="text" id="NombreProducto" name="NombreProducto" value="" placeholder="Introduce un nombre" size="20"> <!--maxsize es para limitar la cantidad ed caracteres-->
			<br>
			<label>Seleccione la categoria</label>
			<select id="categorias" name="categorias">
				<option value="Bebidas Frias">Bebidas Frias</option>
				<option value="Bebidas Calientes">Bebidas Calientes</option>
				<option value="Comida">Comida</option>
				<option value="Postres">Postres</option>
			</select>
			<br>
			<label>Seleccione la porcion</label>
			<select id="porciones" name="ṕorciones">
				<option value="pieza">Por pieza</option>
				<option value="taza">Por taza</option>
				<option value="vaso">Por vaso</option>
				<option value="Postres">Postres</option>
			</select>
			<br>
			<label>Descripcion del producto</label><br>
			<textarea id="descripcion" name="descripcion" cols="30" rows="5">
			</textarea>
			<br>
			<label>Ingredientes del producto</label><br>
			<textarea id="ingredientes" name="ingredientes" cols="30" rows="5">
			</textarea>
			<br>
			<label>Precio(en pesos)</label><br>
			$<input type="number" max="250" min="0" step=".5">
			<br>
			<label>Selecciona un archivo</label>
			<input type="file" id="RutaImagen" name="RutaImagen">
			
			<input type="submit" value="registrar" id="EnviarDatos" name="EnviarDatos" />
			
		</form>
	</body>
	

	</html>