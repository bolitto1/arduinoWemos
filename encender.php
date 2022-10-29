<?php
    echo Enc();
  
    function Enc()
    {
        $servername = "localhost";
        $username = "root";
        $password = "Santarosa.1";
        $dbname = "domotica1";
        // Create connection
        $link = mysqli_connect($servername, $username,  $password, $dbname);
  
        if($link === false){
            die("ERROR: Could not connect. " 
                        . mysqli_connect_error());
        }
        
        $sql = "UPDATE estados SET estado=1 ";
        if(mysqli_query($link, $sql)){
            echo "OK";
        } else {
            echo "ERROR  $sql" 
            . mysqli_error($link);
        } 
        mysqli_close($link);
    
    }
?>