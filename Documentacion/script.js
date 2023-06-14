function openNav(){
    document.getElementById("mobile-menu").style.width = "100%";
}

function closeNav(){
    document.getElementById("mobile-menu").style.width = "0%";
}

// Para barra de navegacion
window.onscroll = function() {barraNavegacion()};

var navbar = document.getElementById("navbar");
var sticky = navbar.offsetTop;

function barraNavegacion() {
  if (window.pageYOffset >= sticky) {
    navbar.classList.add("sticky")
  } else {
    navbar.classList.remove("sticky");
  }
}

// Para redirigir basado en un click
function redirigirIndice() {
  var top = document.getElementById("1indice").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones del Main
function redirigirMain() {
  var top = document.getElementById("1main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainMenuPrincipal() {
  var top = document.getElementById("11main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainFunc() {
  var top = document.getElementById("12main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainAgregar() {
  var top = document.getElementById("121main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainMostrar() {
  var top = document.getElementById("122main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainActualizar() {
  var top = document.getElementById("123main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainBorrar() {
  var top = document.getElementById("124main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainBorrarLista() {
  var top = document.getElementById("125main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainCalcularIndividual() {
  var top = document.getElementById("126main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainCalcularTodos() {
  var top = document.getElementById("127main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirMainSalir() {
  var top = document.getElementById("128main").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones a ListaEmpleados
function redirigirListaEmpleados() {
  var top = document.getElementById("1listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosConstructor() {
  var top = document.getElementById("11listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosAgregar() {
  var top = document.getElementById("12listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosActualizar() {
  var top = document.getElementById("13listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosMostrarCompleto() {
  var top = document.getElementById("14listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosBorrar() {
  var top = document.getElementById("15listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosCalcularIndividual() {
  var top = document.getElementById("16listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosCalcularTodos() {
  var top = document.getElementById("17listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosGuardar() {
  var top = document.getElementById("18listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosCargar() {
  var top = document.getElementById("19listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosVerificar() {
  var top = document.getElementById("110listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosMostrarSimple() {
  var top = document.getElementById("111listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosBuscar() {
  var top = document.getElementById("112listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirListaEmpleadosDestructor() {
  var top = document.getElementById("113listaEmpleados").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones a Nodo
function redirigirNodo() {
  var top = document.getElementById("1nodo").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones a Empleado
function redirigirEmpleado() {
  var top = document.getElementById("1empleado").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirEmpleadoCalcular() {
  var top = document.getElementById("11empleado").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirEmpleadoMostrar() {
  var top = document.getElementById("12empleado").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones a Persona
function redirigirPersona() {
  var top = document.getElementById("1persona").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Redirecciones a Validaciones
function redirigirValidaciones() {
  var top = document.getElementById("1validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirValidacionesAceptar() {
  var top = document.getElementById("11validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirValidacionesTelefono() {
  var top = document.getElementById("12validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirValidacionesDefS() {
  var top = document.getElementById("13validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirValidacionesDefN() {
  var top = document.getElementById("14validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirValidacionesTamano() {
  var top = document.getElementById("15validaciones").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Pagina Manual Usuario
function redirigirRequisitos() {
  var top = document.getElementById("1requisitos").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirInstalacion() {
  var top = document.getElementById("1instalacion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirFuncionamiento() {
  var top = document.getElementById("1funcionamiento").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

// Descripcion
function redirigirDescripcion() {
  var top = document.getElementById("1descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionAgregar() {
  var top = document.getElementById("11descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionMostrar() {
  var top = document.getElementById("12descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionActualizar() {
  var top = document.getElementById("13descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionBorrar() {
  var top = document.getElementById("14descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionBorrarLista() {
  var top = document.getElementById("15descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionCalcularIndividual() {
  var top = document.getElementById("16descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionCalcularTodos() {
  var top = document.getElementById("17descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}

function redirigirDescripcionSalir() {
  var top = document.getElementById("18descripcion").offsetTop-document.getElementById("navbar").offsetHeight-10;
  window.scrollTo(0, top);
}