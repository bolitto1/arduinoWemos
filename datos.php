<?php
    echo test();
  
    function test()
    {
        $servername = "localhost";
        $username = "root";
        $password = "Santarosa.1";
        $dbname = "domotica1";
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }
        
        $sql = "SELECT estado FROM estados LIMIT 1";
        $result = $conn->query($sql);
        
        if ($result->num_rows > 0) {
          // output data of each row
          while($row = $result->fetch_assoc()) {
            return $row["estado"];
          }
        } else {
            return -1;
        }
        $conn->close();        
    }
?>