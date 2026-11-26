function nameValidation(id){
let inputField = document.getElementById("firstname").value;


let elementError=document.getElementById(id+"_error");
let legalLeter= "/^[\p{L}\p{M}]+(?:[ '-][\p{L}\p{M}]+)*$/u";
if(inputField===""){
    elementError.textContent="this field is not empty";
    elementError.style.color="red";

}
else if(!legalLeter.match(inputField))
    {
    elementError.textContent="only letter is allowed";
    elementError.style.color="red";

}
else if(inputField.length<3&&inputField.length>20){
elementError.textContent="allowed letter for name is >3 ";
elementError.style.color="red"
}
else{
    elementError.textContent="";
    elementError.style.color="green";
}
}
function emailValidation(){

}