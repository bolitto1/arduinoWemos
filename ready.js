$(document).ready( function() { 
    // .... your jQuery goodness .... 
   
   // $("foco").prop("src","images/fon.png");
   // $("foco").attr('src',"images/fon.png");
   // document.getElementById("foco").src = "images/fon.png"
    obtener();
});

function Encender()
{
    document.getElementById("foco").src = "images/fon.png"
    $.ajax({
        url: 'encender.php/enc',
        type: 'post',
        data: { "callFunc1": "1"},
        success: function(response) { 
          //  alert(response);
        }
    });
}

function Apagar()
{
    document.getElementById("foco").src = "images/foff.png";
    $.ajax({
        url: 'apagar.php/apa',
        type: 'post',
        data: { "callFunc1": "1"},
        success: function(response) { 
           // alert(response);
        }
    });       
}

function consulta(){
    $.ajax({
        url: 'metodos.php',
        type: 'post',
        data: { "callFunc1": "0"},
        success: function(response) { 
            console.log(response); 
            alert (response);
        
        }
    });
}

function test(){
    $.ajax({
        url: 'test.php',
        type: 'post',
        data: { "callFunc1": "1"},
        success: function(response) { console.log(response); }
    });
}

function obtener(){
    $.ajax({
        url: 'datos.php/test',
        type: 'post',
        data: { "callFunc1": "1"},
        success: function(response) { 
            if (response>0)
            {
                document.getElementById("encendido").checked = true;
                document.getElementById("foco").src = "../pr1/images/fon.png"

            }else{
                document.getElementById("apagado").checked = true;
                document.getElementById("foco").src = "../pr1/images/foff.png"                
            }
            
         }
    });
}
