var trigger = document.getElementById('myImg2');
var modal = document.querySelector(".modal2");
var closeButton = document.querySelector(".close-button2");

function toggleModal() {
    modal.classList.toggle("show-modal");
}

function windowOnClick(event) {
    if (event.target === modal) {
        toggleModal();
    }
}

trigger.addEventListener("click", toggleModal);
closeButton.addEventListener("click", toggleModal);
window.addEventListener("click", windowOnClick);