#include "slidesviewer.h"
#include "controller.h"

QMenuBar * SlidesViewer::createMenu()
{
    QMenuBar *menubar = new QMenuBar(this);
    QMenu *file = new QMenu("File", menubar);
    menubar->addMenu(file);
    QAction *chiudi = new QAction("Chiudi", file);

    connect(chiudi, SIGNAL(triggered(bool)), this, SLOT(close()));

    file->addAction(chiudi);
    QMenu *riproduzione = new QMenu("Riproduzione", menubar);
    menubar->addMenu(riproduzione);

    inizio = new QAction("Inizio", riproduzione);
    precedente = new QAction("Precedente", riproduzione);
    successivo =new QAction("Successivo", riproduzione) ;
    fine = new QAction("Fine", riproduzione);
    autoplay = new QAction("Autoplay", riproduzione);

    riproduzione->addAction(inizio);
    riproduzione->addAction(precedente);
    riproduzione->addAction(successivo);
    riproduzione->addAction(fine);
    riproduzione->addAction(autoplay);

    QMenu *slides = new QMenu("Slides", menubar);
    menubar->addMenu(slides);

    aggiungi = new QAction("Aggiungi", slides);
    rimuovi = new QAction("Rimuovi", slides);
    unisci = new QAction("Unisci", slides);

    slides->addAction(aggiungi);
    slides->addAction(rimuovi);
    slides->addAction(unisci);

    return menubar;
}

SlidesViewer::SlidesViewer(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // aggiungere la barra dei menu
    QMenuBar *menubar = createMenu();
    screen = new SlideScreen(this);
    mainLayout->addWidget(screen);

    mainLayout->addWidget(menubar);

    QHBoxLayout *buttonsBox = new QHBoxLayout(this);
    mainLayout->addLayout(buttonsBox);
    QHBoxLayout *controlsBox = new QHBoxLayout(this);
    buttonsBox->addLayout(controlsBox);

    buttonsBox->setSpacing(150);
    controlsBox->setSpacing(10);
    controlsBox->setContentsMargins(20, 0, 20, 0);

    inizioB = new QPushButton("Inizio", this);
    precedenteB = new QPushButton("Precedente", this);
    successivoB = new QPushButton("Successiva", this);
    fineB = new QPushButton("Fine", this);

    autoplayB = new QPushButton("Autoplay", this);

    controlsBox->addWidget(inizioB);
    controlsBox->addWidget(precedenteB);
    controlsBox->addWidget(successivoB);
    controlsBox->addWidget(fineB);

    buttonsBox->addWidget(autoplayB);
    buttonsBox->setContentsMargins(150, 5   , 150, 5);

    resize(QSize(800, 600)); //for low-res screen
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

    /*string path = "/home/alessandro/dadi.jpg";
    auto m1 = SlideCreator::createSlide(path);
    auto m2 = SlideCreator::composeSlide(m1, SlideCreator::composeSlide(m1, m1, false));
    showSlide(m2, 1, 1);*/

}

void SlidesViewer::showWarning(const QString &message)
{
    QDialog *dialog = new QDialog(this);
    dialog->setLayout(new QVBoxLayout(dialog));
    dialog->layout()->setAlignment(Qt::AlignHCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);
    dialog->layout()->addWidget(new QLabel(message, dialog));
    dialog->show();
}

QString SlidesViewer::showAddDialog()
{
    QString filename =  QFileDialog::getOpenFileName(this, tr("Open file"), "/home", tr("Images (*.png *.jpg)"));
    if(filename == "") throw std::runtime_error("Il nome del file non può essere vuoto");
    return filename;
}

int SlidesViewer::showRemoveDialog()
{
    bool ok = false;
    int num = QInputDialog::getInt(this, tr("Remove slide"), tr("Slide Number"), 0, 0, 2147483647, 1, &ok);
    if(!ok) throw std::runtime_error("Nessuna slide scelta");
    return num;
}

std::pair<int, int> SlidesViewer::showMergeDialog()
{
    bool ok1, ok2;
    ok1 = ok2 = false;

    std::pair<int, int> coppia;
    coppia.first = QInputDialog::getInt(this, tr("Merge Slides"), tr("First slide numeber"), 0, 0, 2147483647, 1, &ok1);
    if(!ok1) throw std::runtime_error("Slide selezionata non valida");

    coppia.second = QInputDialog::getInt(this, tr("Merge Slides"), tr("Second slide numeber"), 0, 0, 2147483647, 1, &ok2);
    if(!ok2) throw std::runtime_error("Slide selezionata non valida");

    return coppia;
}

void SlidesViewer::showSlide(Slide *slide, u_int value, u_int limit)
{
    screen->showSlide(slide);
    screen->updateProgressBar(value, limit);
}

void SlidesViewer::setController(Controller *c)
{
    controller = c;
    //connettere i controlli dei menu con segnale triggered
    connect(inizio, SIGNAL(triggered()), controller, SLOT(begin()));
    connect(precedente, SIGNAL(triggered()), controller, SLOT(previous()));
    connect(successivo, SIGNAL(triggered()), controller, SLOT(next()));
    connect(fine, SIGNAL(triggered()), controller, SLOT(end()));
    connect(autoplay, SIGNAL(triggered()), controller, SLOT(autoplay()));
    connect(aggiungi, SIGNAL(triggered()), controller, SLOT(add()));
    connect(rimuovi, SIGNAL(triggered()), controller, SLOT(remove()));
    connect(unisci, SIGNAL(triggered()), controller, SLOT(merge()));

    //connettere i controlli dei button con il segnale clicked

    connect(inizioB, SIGNAL(clicked()), controller, SLOT(begin()));
    connect(precedenteB, SIGNAL(clicked()), controller, SLOT(previous()));
    connect(successivoB, SIGNAL(clicked()), controller, SLOT(next()));
    connect(fineB, SIGNAL(clicked()), controller, SLOT(end()));
    connect(autoplayB, SIGNAL(clicked()), controller, SLOT(autoplay()));
}
