/*
  ==============================================================================

    CommitMessageComponent.h
    Created: 18 Jul 2017 12:57:00pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class CommitMessageComponent    : public Component
{
public:
    CommitMessageComponent();
    ~CommitMessageComponent();

    void paint (Graphics&) override;
    void resized() override;
    void generateMessage();

private:
	ScopedPointer<StringPool> stringPool;
	ScopedPointer<TextEditor> commitMessageEditor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CommitMessageComponent)
};
