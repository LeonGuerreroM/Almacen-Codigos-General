<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
	"http://www.w3.org/TR/html4/loose.dtd">
<HTML>
	<HEAD>
		<TITLE>
		P&aacute;gina 1 PHP
		</TITLE>
		<meta http-equiv="Contnet-type" content="text/html; charset=UTF-8"> 
	</HEAD>
	<BODY>
		<h1>HTML con PHP</h1>
		
		<?php
		echo "<h1>Escritura</h1>";
		echo "<h1> Hola mundo desde php, con etiquetas </h1>"; //escritura en php //sensible mayusculas y minusculas y caracteres especiales
		echo "<h2>Para construir recursos web</h2>";
		
		
		echo "<h1>Variables</h1>";
		$entero = -230; //como no es fuertemente tipado y no estoy definiendo un tipo de dato para la var desde el inicio, entonces puedo ir usando esta variable y cambiandola de tipo de dato a lo largo de todo el programa
		echo 'valor de $entero: <br>'; //si vamos aponer el texto de nombre de variable se debe usar comillas simples. si se quiere poner el valor de la variable se ponen comillas dobles 
		echo "$entero";
		echo "<br>";
		$entero = 4.73e3;
		echo "$entero";
		echo "<br>";
		$entero = "Hola"; //comillas para los strings
		echo "$entero";
		echo "<br>"; // \n da un salto, \t da un tabulador y van dentro de las comillas dobles. Recuerda que para forzar escritura letra por letra es comillas simples y para ejecutar cosas entre las comillas se usan comillas dobles
		$entero = 0xFF;
		echo "$entero";
		echo "<br>";
		
		echo "<h1>Arreglos con PHP</h1>";
		echo "<h3>Arreglos con indice numerico</h3>";
		echo "<p>EL arreglo se llama \$producto</p>"; //con el slash hacemos que el proximo caracter(especial) este impreso
		$producto[0] = 1; //declaracion de elementos de arreglo
		$producto[1] = "Noticias";
		$producto[2] = "UNiversal";
		$producto[3] = 15;
		$producto[4] = "Nuevas noticias";
		$producto[5] = 7.89;
		echo "<table>
		<tr>
			<th>ID</th>
			<th>Nombre</th>
			<th>Marca</th>
			<th>Existencias</th>
			<th>Informacion General</th>
			<th>Costo</th>
		</tr>";
		echo "<tr>";
			echo "<td>$producto[0]</td>". //Puntito para continuar en el echo en la linea de abajo
				 "<td>$producto[1]</td>".
				 "<td>$producto[2]</td>".
				 "<td>$producto[3]</td>".
				 "<td>$producto[4]</td>".
				 "<td>$producto[5]</td>";
		echo "</tr>";
		echo "</table>"
		?>
		
		<?php
		echo "<h1>Arreglos con PHP</h1>";
		echo "<h3>Arreglos con indice de cadena</h3>";
		$productos['Id']=1;
		$productos['nombre']="noticias";
		$productos['periodico']="univarsal";
		$productos['existencias']=40;
		$productos['Adicionales']="Noticias de hoy";
		$productos['Precio']=7.50;
		
		
		
		?>
		
		
		
		
		
		
	</BODY>	
</HTML>