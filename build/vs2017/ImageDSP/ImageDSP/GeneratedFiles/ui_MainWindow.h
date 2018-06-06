/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionQuit;
    QAction *actionImportGeometry;
    QAction *actionImportTexture;
    QAction *actionExportGeometry;
    QAction *actionExportTexture;
    QAction *actionTextureName;
    QAction *actionTextureDescription;
    QAction *actionDeleteTexture;
    QAction *actionResetModelCamera;
    QAction *actionResetUVCamera;
    QAction *actionResetAllCameras;
    QAction *actionLanguage;
    QAction *actionTextureItemAlwaysEditor;
    QDockWidget *inputImgViewDock;
    QWidget *inputImgViewDockCentralWidget;
    QVBoxLayout *inputImgViewDockLayout;
    QVBoxLayout *inputImgViewLayout;
    QDockWidget *outputImgViewDock;
    QWidget *outputImgViewDockCentralWidget;
    QVBoxLayout *imgViewDockLayout;
    QVBoxLayout *outputImgViewLayout;
    QDockWidget *progListDock;
    QWidget *progListDockCentralWidget;
    QVBoxLayout *progListDockLayout;
    QListView *progList;
    QDockWidget *paramsListDock;
    QWidget *paramsListDockCentralWidget;
    QVBoxLayout *textureListLayout;
    QVBoxLayout *paramsListLayout;
    QDockWidget *inImgsListDock;
    QWidget *inImgsListDockCentralWidget;
    QVBoxLayout *inImgsListDockLayout;
    QListView *inImgsList;
    QDockWidget *outImgsListDock;
    QWidget *outImgsListDockCentralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *saveOutImg;
    QLineEdit *outImageText;
    QPushButton *browseOutImg;
    QLabel *label;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(1176, 1251);
        actionNew = new QAction(mainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(mainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(mainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(mainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionQuit = new QAction(mainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionImportGeometry = new QAction(mainWindow);
        actionImportGeometry->setObjectName(QStringLiteral("actionImportGeometry"));
        actionImportTexture = new QAction(mainWindow);
        actionImportTexture->setObjectName(QStringLiteral("actionImportTexture"));
        actionExportGeometry = new QAction(mainWindow);
        actionExportGeometry->setObjectName(QStringLiteral("actionExportGeometry"));
        actionExportTexture = new QAction(mainWindow);
        actionExportTexture->setObjectName(QStringLiteral("actionExportTexture"));
        actionTextureName = new QAction(mainWindow);
        actionTextureName->setObjectName(QStringLiteral("actionTextureName"));
        actionTextureDescription = new QAction(mainWindow);
        actionTextureDescription->setObjectName(QStringLiteral("actionTextureDescription"));
        actionDeleteTexture = new QAction(mainWindow);
        actionDeleteTexture->setObjectName(QStringLiteral("actionDeleteTexture"));
        actionResetModelCamera = new QAction(mainWindow);
        actionResetModelCamera->setObjectName(QStringLiteral("actionResetModelCamera"));
        actionResetUVCamera = new QAction(mainWindow);
        actionResetUVCamera->setObjectName(QStringLiteral("actionResetUVCamera"));
        actionResetAllCameras = new QAction(mainWindow);
        actionResetAllCameras->setObjectName(QStringLiteral("actionResetAllCameras"));
        actionLanguage = new QAction(mainWindow);
        actionLanguage->setObjectName(QStringLiteral("actionLanguage"));
        actionTextureItemAlwaysEditor = new QAction(mainWindow);
        actionTextureItemAlwaysEditor->setObjectName(QStringLiteral("actionTextureItemAlwaysEditor"));
        actionTextureItemAlwaysEditor->setCheckable(true);
        actionTextureItemAlwaysEditor->setChecked(true);
        inputImgViewDock = new QDockWidget(mainWindow);
        inputImgViewDock->setObjectName(QStringLiteral("inputImgViewDock"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputImgViewDock->sizePolicy().hasHeightForWidth());
        inputImgViewDock->setSizePolicy(sizePolicy);
        inputImgViewDock->setMinimumSize(QSize(500, 500));
        inputImgViewDockCentralWidget = new QWidget();
        inputImgViewDockCentralWidget->setObjectName(QStringLiteral("inputImgViewDockCentralWidget"));
        inputImgViewDockLayout = new QVBoxLayout(inputImgViewDockCentralWidget);
        inputImgViewDockLayout->setObjectName(QStringLiteral("inputImgViewDockLayout"));
        inputImgViewLayout = new QVBoxLayout();
        inputImgViewLayout->setObjectName(QStringLiteral("inputImgViewLayout"));

        inputImgViewDockLayout->addLayout(inputImgViewLayout);

        inputImgViewDock->setWidget(inputImgViewDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), inputImgViewDock);
        outputImgViewDock = new QDockWidget(mainWindow);
        outputImgViewDock->setObjectName(QStringLiteral("outputImgViewDock"));
        sizePolicy.setHeightForWidth(outputImgViewDock->sizePolicy().hasHeightForWidth());
        outputImgViewDock->setSizePolicy(sizePolicy);
        outputImgViewDock->setMinimumSize(QSize(500, 500));
        outputImgViewDockCentralWidget = new QWidget();
        outputImgViewDockCentralWidget->setObjectName(QStringLiteral("outputImgViewDockCentralWidget"));
        imgViewDockLayout = new QVBoxLayout(outputImgViewDockCentralWidget);
        imgViewDockLayout->setObjectName(QStringLiteral("imgViewDockLayout"));
        outputImgViewLayout = new QVBoxLayout();
        outputImgViewLayout->setObjectName(QStringLiteral("outputImgViewLayout"));

        imgViewDockLayout->addLayout(outputImgViewLayout);

        outputImgViewDock->setWidget(outputImgViewDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), outputImgViewDock);
        progListDock = new QDockWidget(mainWindow);
        progListDock->setObjectName(QStringLiteral("progListDock"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progListDock->sizePolicy().hasHeightForWidth());
        progListDock->setSizePolicy(sizePolicy1);
        progListDock->setMinimumSize(QSize(300, 300));
        progListDock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        progListDockCentralWidget = new QWidget();
        progListDockCentralWidget->setObjectName(QStringLiteral("progListDockCentralWidget"));
        progListDockLayout = new QVBoxLayout(progListDockCentralWidget);
        progListDockLayout->setObjectName(QStringLiteral("progListDockLayout"));
        progList = new QListView(progListDockCentralWidget);
        progList->setObjectName(QStringLiteral("progList"));
        progList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        progList->setProperty("showDropIndicator", QVariant(false));

        progListDockLayout->addWidget(progList);

        progListDock->setWidget(progListDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), progListDock);
        paramsListDock = new QDockWidget(mainWindow);
        paramsListDock->setObjectName(QStringLiteral("paramsListDock"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(paramsListDock->sizePolicy().hasHeightForWidth());
        paramsListDock->setSizePolicy(sizePolicy2);
        paramsListDock->setMinimumSize(QSize(300, 300));
        paramsListDockCentralWidget = new QWidget();
        paramsListDockCentralWidget->setObjectName(QStringLiteral("paramsListDockCentralWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(paramsListDockCentralWidget->sizePolicy().hasHeightForWidth());
        paramsListDockCentralWidget->setSizePolicy(sizePolicy3);
        textureListLayout = new QVBoxLayout(paramsListDockCentralWidget);
        textureListLayout->setObjectName(QStringLiteral("textureListLayout"));
        paramsListLayout = new QVBoxLayout();
        paramsListLayout->setObjectName(QStringLiteral("paramsListLayout"));

        textureListLayout->addLayout(paramsListLayout);

        paramsListDock->setWidget(paramsListDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), paramsListDock);
        inImgsListDock = new QDockWidget(mainWindow);
        inImgsListDock->setObjectName(QStringLiteral("inImgsListDock"));
        sizePolicy2.setHeightForWidth(inImgsListDock->sizePolicy().hasHeightForWidth());
        inImgsListDock->setSizePolicy(sizePolicy2);
        inImgsListDock->setMinimumSize(QSize(300, 300));
        inImgsListDock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        inImgsListDockCentralWidget = new QWidget();
        inImgsListDockCentralWidget->setObjectName(QStringLiteral("inImgsListDockCentralWidget"));
        inImgsListDockLayout = new QVBoxLayout(inImgsListDockCentralWidget);
        inImgsListDockLayout->setObjectName(QStringLiteral("inImgsListDockLayout"));
        inImgsList = new QListView(inImgsListDockCentralWidget);
        inImgsList->setObjectName(QStringLiteral("inImgsList"));
        inImgsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        inImgsList->setProperty("showDropIndicator", QVariant(true));

        inImgsListDockLayout->addWidget(inImgsList);

        inImgsListDock->setWidget(inImgsListDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), inImgsListDock);
        outImgsListDock = new QDockWidget(mainWindow);
        outImgsListDock->setObjectName(QStringLiteral("outImgsListDock"));
        outImgsListDockCentralWidget = new QWidget();
        outImgsListDockCentralWidget->setObjectName(QStringLiteral("outImgsListDockCentralWidget"));
        verticalLayout_2 = new QVBoxLayout(outImgsListDockCentralWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        saveOutImg = new QPushButton(outImgsListDockCentralWidget);
        saveOutImg->setObjectName(QStringLiteral("saveOutImg"));

        gridLayout->addWidget(saveOutImg, 1, 1, 1, 1);

        outImageText = new QLineEdit(outImgsListDockCentralWidget);
        outImageText->setObjectName(QStringLiteral("outImageText"));

        gridLayout->addWidget(outImageText, 0, 0, 1, 1);

        browseOutImg = new QPushButton(outImgsListDockCentralWidget);
        browseOutImg->setObjectName(QStringLiteral("browseOutImg"));
        browseOutImg->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(browseOutImg, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        label = new QLabel(outImgsListDockCentralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(label);

        outImgsListDock->setWidget(outImgsListDockCentralWidget);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), outImgsListDock);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Image DSP", nullptr));
        actionNew->setText(QApplication::translate("mainWindow", "&New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("mainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("mainWindow", "&Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("mainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("mainWindow", "&Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("mainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("mainWindow", "Save &As", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveAs->setShortcut(QApplication::translate("mainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("mainWindow", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("mainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionImportGeometry->setText(QApplication::translate("mainWindow", "&Geometry", nullptr));
#ifndef QT_NO_SHORTCUT
        actionImportGeometry->setShortcut(QApplication::translate("mainWindow", "Ctrl+G", nullptr));
#endif // QT_NO_SHORTCUT
        actionImportTexture->setText(QApplication::translate("mainWindow", "&Texture", nullptr));
#ifndef QT_NO_SHORTCUT
        actionImportTexture->setShortcut(QApplication::translate("mainWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionExportGeometry->setText(QApplication::translate("mainWindow", "&Geometry", nullptr));
        actionExportTexture->setText(QApplication::translate("mainWindow", "&Texture", nullptr));
        actionTextureName->setText(QApplication::translate("mainWindow", "Texture Name", nullptr));
        actionTextureDescription->setText(QApplication::translate("mainWindow", "Texture Description", nullptr));
        actionDeleteTexture->setText(QApplication::translate("mainWindow", "D&elete Texture", nullptr));
        actionResetModelCamera->setText(QApplication::translate("mainWindow", "Reset &Model Camera", nullptr));
        actionResetUVCamera->setText(QApplication::translate("mainWindow", "Reset &UV Camera", nullptr));
        actionResetAllCameras->setText(QApplication::translate("mainWindow", "Reset &All Cameras", nullptr));
#ifndef QT_NO_SHORTCUT
        actionResetAllCameras->setShortcut(QApplication::translate("mainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionLanguage->setText(QApplication::translate("mainWindow", "&Language", nullptr));
        actionTextureItemAlwaysEditor->setText(QApplication::translate("mainWindow", "Texture Item Always Editor", nullptr));
        inputImgViewDock->setWindowTitle(QApplication::translate("mainWindow", "Input Image", nullptr));
        outputImgViewDock->setWindowTitle(QApplication::translate("mainWindow", "Output Image", nullptr));
        progListDock->setWindowTitle(QApplication::translate("mainWindow", "Programs", nullptr));
        paramsListDock->setWindowTitle(QApplication::translate("mainWindow", "Parameters", nullptr));
        inImgsListDock->setWindowTitle(QApplication::translate("mainWindow", "Input Images", nullptr));
        outImgsListDock->setWindowTitle(QApplication::translate("mainWindow", "Output Images", nullptr));
        saveOutImg->setText(QApplication::translate("mainWindow", "Save", nullptr));
        browseOutImg->setText(QApplication::translate("mainWindow", "Browse...", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
