#include "slidesviewer.h"

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

    QAction *inizio = new QAction("Inizio", riproduzione);
    QAction *precendete = new QAction("Precedente", riproduzione);
    QAction *successivo =new QAction("Successivo", riproduzione) ;
    QAction *fine = new QAction("Fine", riproduzione);
    QAction *autoplay = new QAction("Autoplay", riproduzione);

    riproduzione->addAction(inizio);
    riproduzione->addAction(precendete);
    riproduzione->addAction(successivo);
    riproduzione->addAction(fine);
    riproduzione->addAction(autoplay);

    QMenu *slides = new QMenu("Slides", menubar);
    menubar->addMenu(slides);

    QAction *aggiungi = new QAction("Aggiungi", slides);
    QAction *rimuovi = new QAction("Rimuovi", slides);
    QAction *unisci = new QAction("Unisci", slides);

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

    resize(QSize(800, 600)); //for low-res screen
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

    string path = "/home/alessandro/dadi.jpg";
    auto m1 = SlideCreator::createSlide(path);
    auto m2 = SlideCreator::composeSlide(m1, SlideCreator::composeSlide(m1, m1, false));
    showSlide(m2, 1, 1);

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
