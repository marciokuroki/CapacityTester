/****************************************************************************
**
** Copyright (C) 2016 Philip Seeger
** This file is part of CapacityTester.
**
** CapacityTester is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** CapacityTester is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with CapacityTester. If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef CAPACITYTESTERGUI_HPP
#define CAPACITYTESTERGUI_HPP

#include <cassert>

#include <QDebug>
#include <QApplication>
#include <QPixmap>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QTimer>
#include <QMessageBox>
#include <QThread>
#include <QPainter>
#include <QBrush>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QMutexLocker>

#include "size.hpp"
#include "volumetester.hpp"
#include "selectionwindow.hpp"

class CapacityTesterGui : public QMainWindow
{
    Q_OBJECT

signals:

public:

    CapacityTesterGui(QWidget *parent = 0, Qt::WindowFlags flags = 0);

private:

    bool
    closing;

    QString
    selected_mountpoint;

    QLineEdit
    *txt_volume;

    QPushButton
    *btn_select_volume;

    QPushButton
    *btn_start_volume_test;

    QPushButton
    *btn_stop_volume_test;

    QPushButton
    *btn_quit;

    QLineEdit
    *txt_capacity;

    QLineEdit
    *txt_used;

    QLineEdit
    *txt_available;

    QLabel
    *lbl_pro_testing;

    QLabel
    *lbl_pro_left_light;

    QLabel
    *lbl_pro_right_light;

    QTimer
    *tmr_pro_testing;

    QGraphicsOpacityEffect
    *eff_pro_left;

    QGraphicsOpacityEffect
    *eff_pro_right;

    QPropertyAnimation
    *ani_pro_left;

    QPropertyAnimation
    *ani_pro_right;

    Size
    total_test_size;

    QProgressBar
    *pro_initializing;

    QProgressBar
    *pro_writing;

    QProgressBar
    *pro_verifying;

    QLineEdit
    *txt_write_speed;

    QLineEdit
    *txt_read_speed;

    QElapsedTimer
    tmr_total_test_time;

    QLineEdit
    *txt_time;

    QPlainTextEdit
    *txt_result;

    QPixmap
    progressLightPixmap(const QColor &color);

    QPointer<VolumeTester>
    worker;

private slots:

    void
    closeEvent(QCloseEvent *event);

    void
    showDriveWindow();

    void
    unloadVolume();

    void
    setCapacityFields(VolumeTester &tester);

    void
    loadVolume(const QString &mountpoint);

    void
    startVolumeTest();

    void
    stopVolumeTest();

    void
    succeededVolumeTest();

    void
    failedVolumeTest(int error_type);

    void
    completedVolumeTest();

    void
    updateProgressLabel();

    void
    initializationStarted(qint64 total);

    void
    initialized(qint64 bytes, double avg_speed);

    void
    writeStarted();

    void
    verifyStarted();

    void
    createFailed(int index, qint64 start);

    void
    writeFailed(qint64 start, int size);

    void
    verifyFailed(qint64 start, int size);

    void
    written(qint64 written, double avg_speed);

    void
    verified(qint64 read, double avg_speed);

};

#endif
