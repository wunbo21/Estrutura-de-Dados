<?php
  /* Itens obrigatórios */
  $host="localhost";
  $user="root";
  $pass="";
  $banco="aula09";
  $conexao = mysqli_connect($host, $user, $pass) or die(mysql_error());
  mysqli_select_db($conexao,$banco) or die(mysqli_error());
  /* Fim dos itens obrigatórios */
  
  $titulo = $_POST['titulo_livro'];
  $autor = $_POST['autor_livro'];
  $editora = $_POST['nomes_editoras'];
  $valor = $_POST['valor_livro'];
  
  if($_POST['button']=="Cadastrar"){
    $sql="insert into cadastro(titulo, autor, editora, valor) values('$titulo','$autor','$editora','$valor')";
    if(mysqli_query($conexao, $sql)){
      echo"<center><h1>Cadastro realizado com sucesso!!!</h1></center>";
    }
  }    
    
  
  if($_POST['button']=="Deletar"){
    $sql=  mysqli_query($conexao,"delete from cadastro where titulo='{$titulo}'");
    echo"<h1>O livro '$titulo' foi deletado com sucesso!</h1>"; 
  }
  
  if($_POST['button']=="Atualizar"){
    $sql=mysqli_query($conexao,"update cadastro set autor='{$autor}' where titulo='{$titulo}'");
    echo"<h1>Autor $autor foi atualizado com sucesso!</h1>";
  }
 
  if($_POST['button']=="Selecionar"){
    $busca="select * from cadastro where titulo='{$titulo}'";
    $sql = mysqli_query($conexao,$busca);
    $i=0;
    while($linha = mysqli_fetch_array($sql)){
      echo"<input type='text' value='".$linha['titulo']."'/>";
      echo"<input type='text' value='".$linha['autor']."'/>";
      echo"<input type='text' value='".$linha['editora']."'/>";
      echo"<input type='text' value='".$linha['valor']."'/>";
      $i++;
    }
  }
  
?><a href="aula_05.html">Voltar</a>