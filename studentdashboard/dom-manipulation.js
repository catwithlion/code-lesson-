document.getElementById("");







let changeColorButton=document.querySelector("#changeColor");
changeColorButton.addEventListener("click",function(){
    let cards=document.querySelectorAll("#card");
    cards.forEach(function(card)  {
        card.style.backgrouncolor="lightblue";

    })

})
document.getElementById("changecolor")
.addEventListener("click",function ()
{
    const card=document.querySelectorAll(".card");
    card.forEach(function (cards){
     cards.style.backgrouncolor="lightblue";                

    })
}
)
