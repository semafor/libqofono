/*
 * This file is part of ofono-qt
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: Alexander Kanavin <alex.kanavin@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include <QtTest/QtTest>
#include <QtCore/QObject>

#include "../../../src/qofononetworkregistration.h"
#include "../../../src/qofononetworkoperator.h"

#include <QtDebug>


class TestQOfonoNetworkOperator : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
    m = new QOfonoNetworkRegistration(this);
    m->setModemPath("/phonesim");

    QCOMPARE(m->isValid(), true);
    }

    void testQOfonoNetworkOperator()
    {
        QSignalSpy scan(m, SIGNAL(scanComplete(bool, QStringList)));
        m->scan();
        QTest::qWait(5000);
        QCOMPARE(scan.count(), 1);
        QVariantList scanList = scan.takeFirst();
        QCOMPARE(scanList.at(0).toBool(), true);
        QStringList opIdList = scanList.at(1).toStringList();
        QVERIFY(opIdList.count() > 0);

        int op1 = -1;
        int op2 = -1;
    QList<QOfonoNetworkOperator> opList;
    foreach(QString opId, opIdList)
    {
        QOfonoNetworkOperator op;
        op.setOperatorPath(opId);
        opList << op;
        if (op1 == -1 && op.status() == "current")
            op1 = opIdList.indexOf(opId);
        if (op2 == -1 && op.status() == "available")
            op2 = opIdList.indexOf(opId);
    }

    QVERIFY(op1 != -1);
    QVERIFY(op2 != -1);
    QVERIFY(opList[op1].name().length() > 0);
    QVERIFY(opList[op2].name().length() > 0);
    QVERIFY(opList[op1].mcc().length() > 0);
    QVERIFY(opList[op2].mcc().length() > 0);
    QVERIFY(opList[op1].mnc().length() > 0);
    QVERIFY(opList[op2].mnc().length() > 0);
    QVERIFY(opList[op1].technologies().count() > 0);
    QVERIFY(opList[op2].technologies().count() > 0);

    QSignalSpy op1Register(&opList[op1], SIGNAL(registerComplete(bool)));
    QSignalSpy op2Register(&opList[op2], SIGNAL(registerComplete(bool)));
    QSignalSpy op1Status(&opList[op1], SIGNAL(statusChanged(QString)));
    QSignalSpy op2Status(&opList[op2], SIGNAL(statusChanged(QString)));

    QSignalSpy mode(m, SIGNAL(modeChanged(QString)));
    QSignalSpy status(m, SIGNAL(statusChanged(QString)));
    QSignalSpy lac(m, SIGNAL(locationAreaCodeChanged(uint)));
    QSignalSpy cellId(m, SIGNAL(cellIdChanged(uint)));
    QSignalSpy mcc(m, SIGNAL(mccChanged(QString)));
    QSignalSpy mnc(m, SIGNAL(mncChanged(QString)));
    QSignalSpy tech(m, SIGNAL(technologyChanged(QString)));
    QSignalSpy name(m, SIGNAL(nameChanged(QString)));
    QSignalSpy strength(m, SIGNAL(strengthChanged(uint)));
    QSignalSpy base(m, SIGNAL(baseStationChanged(QString)));

    opList[op2].registerOperator();
    QTest::qWait(5000);
    opList[op1].registerOperator();
    QTest::qWait(5000);

    QCOMPARE(op1Register.count(), 1);
    QCOMPARE(op1Register.takeFirst().at(0).toBool(), true);
    QCOMPARE(op2Register.count(), 1);
    QCOMPARE(op2Register.takeFirst().at(0).toBool(), true);
    QCOMPARE(op1Status.count(), 2);
    QCOMPARE(op1Status.takeFirst().at(0).toString(), QString("available"));
    QCOMPARE(op1Status.takeFirst().at(0).toString(), QString("current"));
    QCOMPARE(op2Status.count(), 2);
    QCOMPARE(op2Status.takeFirst().at(0).toString(), QString("current"));
    QCOMPARE(op2Status.takeFirst().at(0).toString(), QString("available"));

    QCOMPARE(mcc.count(), 2);
    QCOMPARE(mnc.count(), 2);
    QCOMPARE(name.count(), 2);
    }


    void cleanupTestCase()
    {

    }


private:
    QOfonoNetworkRegistration *m;
};

QTEST_MAIN(TestQOfonoNetworkOperator)
#include "tst_qofononetworkoperator.moc"
