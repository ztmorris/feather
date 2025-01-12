// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2020-2023 The Monero Project

#ifndef FEATHER_SETTINGS_H
#define FEATHER_SETTINGS_H

#include <QAbstractButton>
#include <QDialog>
#include <QSettings>

#include "appcontext.h"
#include "widgets/NodeWidget.h"

namespace Ui {
    class Settings;
}

class Settings : public QDialog
{
Q_OBJECT

public:
    explicit Settings(QSharedPointer<AppContext> ctx, QWidget *parent = nullptr);
    ~Settings() override;

signals:
    void preferredFiatCurrencyChanged(QString currency);
    void skinChanged(QString skinName);
    void blockExplorerChanged(QString blockExplorer);
    void amountPrecisionChanged(int precision);
    void websocketStatusChanged(bool enabled);

public slots:
    void checkboxExternalLinkWarn();
    void fiatCurrencySelected(int index);
    void comboBox_skinChanged(int pos);
    void comboBox_amountPrecisionChanged(int pos);
    void comboBox_dateFormatChanged(int pos);
    void comboBox_timeFormatChanged(int pos);
    void comboBox_balanceDisplayChanged(int pos);
    void comboBox_blockExplorerChanged(int pos);
    void comboBox_redditFrontendChanged(int pos);
    void comboBox_localMoneroFrontendChanged(int pos);

private:
    void setupGeneralTab();
    void setupPrivacyTab();
    void setupNodeTab();
    void setupPathsTab();
    void setupLinksTab();

    void setupSkinCombobox();
    void setupLocalMoneroFrontendCombobox();
    void enableWebsocket(bool enabled);

    void closeEvent(QCloseEvent *event) override;

    QScopedPointer<Ui::Settings> ui;
    QSharedPointer<AppContext> m_ctx;

    QStringList m_skins{"Native", "QDarkStyle", "Breeze/Dark", "Breeze/Light"};
    QStringList m_dateFormats{"yyyy-MM-dd", "MM-dd-yyyy", "dd-MM-yyyy"};
    QStringList m_timeFormats{"hh:mm", "hh:mm ap"};
};

#endif // FEATHER_SETTINGS_H
